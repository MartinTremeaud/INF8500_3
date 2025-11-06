#ifndef KERNEL_H
#define KERNEL_H

#include "stdint.h"
#include "application_definitions.h"

uint8_t sobel_operator(const uint32_t index, const uint32_t img_width, uint8_t* input, const uint8_t buf_height);
uint8_t getVal(int index, int xDiff, int yDiff, int img_width, uint8_t* input, const uint8_t buf_height);
uint8_t sobel_operator_2D(const int row, const int col, uint8_t Y[4][60]);

#endif
