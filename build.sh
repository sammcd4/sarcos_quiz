#! /bin/bash

# generate makefile
cmake -S . -B ./build

# compile
make -C ./build