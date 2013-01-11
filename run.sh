#!/bin/bash

echo "Hold on to your scrollback buffers!"
cmake .
make
./testruder && yes | ./textruder
