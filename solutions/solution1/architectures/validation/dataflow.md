# Data flow report for solution1/validation

This report contains the data flow of the application.

## Data flow

``` dot
digraph "solution1/validation" {
    fontname="Helvetica,Arial,sans-serif"
    concentrate=true
    node [fontname="Helvetica,Arial,sans-serif"]
    edge [fontname="Helvetica,Arial,sans-serif"]
    node [style=filled];
    controller0 -> register_file0
    controller0 -> simulation_serialization0
    controller0 -> sobel0
    controller0 -> zynq_ddr0
    register_file0 -> sobel0
    sobel0 -> controller0
    sobel0 -> zynq_ddr0
    zynq_ddr0 -> controller0
    zynq_ddr0 -> sobel0
	controller0 [shape=oval color="#e9c3c7" tooltip="controller0 [spacecodesign.com module controller0 1.0]"]
	register_file0 [shape=box color="#fffbe7" tooltip="register_file0 [spacecodesign.com ip register_file 1.0]"]
	simulation_serialization0 [shape=box color="#e1e1e1" tooltip="simulation_serialization0 [spacecodesign.com device simulation_serialization0 1.0]"]
	sobel0 [shape=oval color="#e9c3c7" tooltip="sobel0 [spacecodesign.com module sobel0 1.0]"]
	zynq_ddr0 [shape=box color="#fffbe7" tooltip="zynq_ddr0 [spacecodesign.com memory bram 1.0]"]
}
```