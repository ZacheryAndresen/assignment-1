#include "array_ops.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

ArrayOps::ArrayOps() {
    size = 0;  // Initialize the size to 0
}

void ArrayOps::loadArrayFromFile(const char* filename) {
    ifstream infile(filename);
    if (!infile) {
        throw runtime_error("Error: Unable to open input file");
    }
    while (infile >> arr[size] && size < MAX_SIZE) {
        size++;
    }
}

int ArrayOps::find(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;  // If the value is not found
}

void ArrayOps::modify(int index, int newValue, int& oldValue) {
    if (index < 0 || index >= size) {
        throw out_of_range("Error: Index out of bounds");
    }
    oldValue = arr[index];
    arr[index] = newValue;
}

void ArrayOps::add(int value) {
    if (size >= MAX_SIZE) {
        throw overflow_error("Error: Array is full");
    }
    arr[size] = value;
    size++;
}

void ArrayOps::remove(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Error: Index out of bounds");
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;  // Reduce the size of the array
}
