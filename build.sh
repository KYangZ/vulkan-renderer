#!/bin/bash

mkdir build/
./compile-shaders.sh
cp -r models/ build/models/
cp -r textures/ build/textures/

cd build/
cmake ..
make

# to run, cd into build directory and then run executable