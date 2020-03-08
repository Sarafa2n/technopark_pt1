#!/bin/bash

mkdir build
cd build
cmake ..
cmake --build .
ctest .
cd ..
cppcheck --project=compile_commands.json
