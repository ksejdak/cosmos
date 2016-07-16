target remote :2331

set output-radix 16

monitor reset halt
#ddr_init
load
monitor reset halt

break _start
break main