

#include "kernel.h"

#define ABS(x)          ((x>0)? x : -x)

uint8_t sobel_operator(const uint32_t index, const uint32_t img_width, uint8_t* input, const uint8_t buf_height) {

	int x_weight = 0;
	int y_weight = 0;

	unsigned edge_weight;
	uint8_t edge_val;

	const char x_op[3][3] =
	{ { -1,0,1 },
	{ -2,0,2 },
	{ -1,0,1 } };

	const char y_op[3][3] =
	{ { 1,2,1 },
	{ 0,0,0 },
	{ -1,-2,-1 } };

	//Compute approximation of the gradients in the X-Y direction
L3:	for (int i=0;i<3;i++) {
L4:		for (int j=0;j<3;j++) {
			// X direction gradient
			x_weight = x_weight + (getVal(index, i - 1, j - 1, img_width, input, buf_height) * x_op[i][j]);
			// Y direction gradient
			y_weight = y_weight + (getVal(index, i - 1, j - 1, img_width, input, buf_height) * y_op[i][j]);
		}
	}

		edge_weight = ABS(x_weight) + ABS(y_weight);

		edge_val = (255 - (uint8_t)(edge_weight));

		//Edge thresholding
		if (edge_val > 200)
			return 255;
		else if (edge_val < 100)
			return 0;
		return edge_val;
}

uint8_t getVal(int index, int xDiff, int yDiff, int img_width, uint8_t* input, const uint8_t buf_height) {
	int fullIndex = (index + (yDiff * img_width)) + xDiff;
	if (fullIndex < 0)
	{
		//Cas ou on doit chercher la derniere ligne
//		printf("debordement en haut de 0 (avant): %d %d\n", fullIndex, index);
		fullIndex += img_width * buf_height;
//		printf("debordement en haut de 0 (apres): %d %d\n", fullIndex, index);
	}
	else if (fullIndex >= img_width * buf_height)
	{
		//Cas ou on doit aller chercher la premiere ligne
//		printf("debordement en bas de 4 (avant): %d %d\n", fullIndex, index);
		fullIndex -= img_width * buf_height;
//		printf("debordement en bas de 4 (apres): %d %d\n", fullIndex, index);
	}
//	else printf("pas de debordement (full index, index, xDiff, yDiff, img_width): %d %d %d %d %d\n", fullIndex, index, xDiff, yDiff, img_width);

return input[fullIndex];
};

uint8_t sobel_operator_2D(const int row, const int col, uint8_t Y[4][60])
{
//#pragma HLS inline
	int x_weight = 0;
	int y_weight = 0;

	unsigned edge_weight;
	uint8_t edge_val;

	const char x_op[3][3] ={{-1,0,1},
							{-2,0,2},
							{-1,0,1}};

	const char y_op[3][3] ={{1,2,1},
							{0,0,0},
							{-1,-2,-1}};

	//Compute approximation of the gradients in the X-Y direction
	L3: for(int i = 0; i < 3; i++){
//#pragma HLS unroll
		L4: for(int j = 0; j < 3; j++){
//#pragma HLS unroll

			// X direction gradient
			x_weight = x_weight + Y[(row+i-1)%4][col+j-1] * x_op[i][j];

			// Y direction gradient
			y_weight = y_weight + Y[(row+i-1)%4][col+j-1] * y_op[i][j];
		}
	}

	edge_weight = ABS(x_weight) + ABS(y_weight);

	edge_val = (255-(uint8_t)(edge_weight));

	//Edge thresholding
	if(edge_val > 200)
		edge_val = 255;
	else if(edge_val < 100)
		edge_val = 0;

	return edge_val;
}

