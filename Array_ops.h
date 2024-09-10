#ifndef ARRAY_OPS_H
#define ARRAY_OPS_H

const int MAX_SIZE = 100;

class ArrayOps {
private:
    int arr[MAX_SIZE];
    int size;
public:
    ArrayOps();  // Constructor to initialize the array from the input file

    int find(int value);  // Function to find an integer in the array

    void modify(int index, int newValue, int& oldValue);  // Function to modify an integer

    void add(int value);  // Function to add a new integer to the array

    void remove(int index);  // Function to remove or replace an integer with 0

    void loadArrayFromFile(const char* filename);  // Function to load array from file
};

#endif
