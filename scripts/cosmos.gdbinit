target remote :2331

set output-radix 16

monitor reset
DDRInit
load
monitor reset halt

break main