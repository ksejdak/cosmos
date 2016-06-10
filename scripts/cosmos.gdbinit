target remote localhost:3333

set output-radix 16

monitor reset halt
load
monitor reset halt

break main