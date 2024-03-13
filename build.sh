#!/bin/bash

./compile-shaders.sh
cd build/
cmake ..
make

# to run, cd into build directory and then run executable