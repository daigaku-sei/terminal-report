#!/bin/bash

# Install Conan (if not already installed)
pip install conan

# Run Conan install
conan install .

# Create a build directory
mkdir build
cd build

# Generate build files using CMake
cmake ..

# Build the project
cmake --build .

# Run the program
./main