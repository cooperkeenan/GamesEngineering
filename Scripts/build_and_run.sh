#!/bin/bash

# Remove the existing build directory if it exists
rm -rf build

# Create a new build directory
mkdir build
cd build

# Run CMake configuration
echo "Configuring project with CMake..."
cmake ..

# Build the project
echo "Building project..."
cmake --build .

# Check if the build succeeded
if [ $? -eq 0 ]; then
    echo "Build successful! Running PRACTICAL_3..."
    # Run the PRACTICAL_3 executable
    ./bin/PRACTICAL_3
else
    echo "Build failed. Please check for errors."
fi
