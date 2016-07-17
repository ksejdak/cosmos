target remote :2331

set output-radix 16

monitor reset halt
#ddr_init
load

break main