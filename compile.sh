#!/bin/bash

# Compile the main program along with matrix functions
g++ main.cpp matrix.cpp matrixui.cpp RowTransform.cpp -o matrix_program

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful! Running the program..."
    # Run the program
    ./matrix_program
else
    echo "Compilation failed."
fi