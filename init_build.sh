#!/bin/bash

if [ -d "./build" ]; then
  yes yes | rm -rf build
fi

cmake -E make_directory build

cmake -E chdir build cmake .. -G Ninja \
  -DCMAKE_C_COMPILER=/usr/bin/clang \
  -DCMAKE_CXX_COMPILER=/usr/bin/clang++