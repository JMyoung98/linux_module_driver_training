# !/bin/bash

sudo mknod /dev/leddev c 240 1; sudo chmod 666 /dev/leddev

sudo insmod *.ko
