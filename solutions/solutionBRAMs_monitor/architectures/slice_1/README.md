# Architecture `validation`

You can use this Markdown file to describe the solution, architecture or component.

You may view this file either within SpaceStudio (by opening it in the Project Explorer and going to the 'Preview' tab), or via other Markdown viewers (such as VSCode's Preview), however some features, such as Graphviz, may not be shown as within SpaceStudio in such viewers.

## Markdown examples

For more reference on Markdown, see [this page for GitHub's flavor of Markdown](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).

Text: A paragraph requires no special syntax. The contents of the `.md` file
can
include
as
many
single
newlines
as
desired,
which does not break the text in multiple paragraphs (two consecutive newlines are required for breaking into multiple paragraphs).

Italic: This module performs _fixed-point computation_.

Bold: Our FFT **does not** like butterflies.

Link: [See here](https://example.com/) for more details on the algorithm.

Inline code: The data is read from module `fmc_reader`.

Unordered list:

- Changed 'long' to fixed-size 'uint32_t'
- Made the module process batches of 1ms of data.
- Implemented ping-pong buffers

Ordered list:

1. Read 1ms of signal (via `DeviceRead()`)
1. Compute FIR filter on data
1. Write filtered data (via `ModuleWrite()`) to `my_next_module`.


Block of code:

```cpp
#include <iostream>

int main(int argc, char** argv) {
	// "Hello World" example
	std::cout << "Hello, World!\n";
	return 0;
}
```

```bash
#!/bin/bash -xe
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)"
echo "Dir of current script is: $SCRIPT_DIR"
```

Table:

| Task         | %time | Comments    |
|--------------|:-----:|------------:|
| Input Reader | 2     | -           |
| Resampler    | 3     | In hardware |
| Dot product  | 15    | In software |

Title levels:

# Level-1 title

## Level-2 title

### Level-3 title

## Graphviz DOT example

``` dot
digraph {
	subgraph cluster_0 {
		label="main()";
		ModuleRead -> compute;
		compute -> ModuleWrite;
	}
}
```

## Math example

This is an in-line $(x+1)^2$ equation.

$$
(x+1)^2=(x+1)(x+1)
$$

$$
a+1 \above 1pt b
$$

$$
u(x) =
	\begin{cases}
		\exp{x} & \text{if } x \geq 0 \\
		1       & \text{if } x < 0
	\end{cases}
$$

## LaTeX

\begin{equation}
	f(x)=(x+a)(x+b)
\end{equation}

## PlanUML

@startuml
participant P as "producer0"
participant F as "fifo"
participant C as "consumer0"

P --> F: ModuleWrite
F --> C: ModuleRead
@enduml
