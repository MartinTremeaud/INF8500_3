# FPGA estimation report for solution1/zynq

This report contains a summary of FPGA resource utilization and a FPGA resource utilization for each component instance found in architecture.

## Summary

| Name            | Block RAMS | DSPs | FlipFlops | LUT Elements |
|-----------------| ------:| ------:| ------:| ------:|
| Used            | 2050 | 2 | 2889 | 2857 |
| Available       | 280 | 220 | 106400 | 53200 |
| Utilization (%) | 732,14 | 0,91 | 2,72 | 5,37 |

## Details

| Name             | Block RAMS | DSPs | FlipFlops | LUT Elements |
|------------------| ------:| ------:| ------:| ------:|
| axi4_interconnect0 (%) | 0 (0,00) | 0 (0,00) | 431 (0,41) | 268 (0,50) |
| axi4_interconnect1 (%) | 0 (0,00) | 0 (0,00) | 340 (0,32) | 212 (0,40) |
| axi_slave_adapter0 (%) | 0 (0,00) | 0 (0,00) | 37 (0,03) | 25 (0,05) |
| axi_slave_adapter1 (%) | 0 (0,00) | 0 (0,00) | 37 (0,03) | 25 (0,05) |
| msa_fifo_read0 (%) | 1 (0,36) | 0 (0,00) | 171 (0,16) | 123 (0,23) |
| msa_fifo_write0 (%) | 1 (0,36) | 0 (0,00) | 203 (0,19) | 129 (0,24) |
| pic0 (%) | 0 (0,00) | 0 (0,00) | 70 (0,07) | 71 (0,13) |
| processor_fifo_adapter0 (%) | 0 (0,00) | 0 (0,00) | 277 (0,26) | 19 (0,04) |
| register_adapter0 (%) | 0 (0,00) | 0 (0,00) | 271 (0,25) | 104 (0,20) |
| register_file0 (%) | 0 (0,00) | 0 (0,00) | 195 (0,18) | 48 (0,09) |
| reset_manager0 (%) | 0 (0,00) | 0 (0,00) | 40 (0,04) | 18 (0,03) |
| sobel0 (%) | 2048 (731,43) | 2 (0,91) | 817 (0,77) | 1703 (3,20) |
| zynq0 (%) | 0 (0,00) | 0 (0,00) | 0 (0,00) | 112 (0,21) |
