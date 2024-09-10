#include "array_ops.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    ArrayOps arrayOps;
    try {
        // Load the array from file
        arrayOps.loadArrayFromFile("input.txt");

        // Modify a value with error handling
        int index, newValue, oldValue;
        cout << "Enter index to modify: ";
        cin >> index;
        cout << "Enter new value: ";
        cin >> newValue;
        try {
            arrayOps.modify(index, newValue, oldValue);
            cout << "Old Value: " << oldValue << ", New Value: " << newValue << endl;
        }
        catch (const out_of_range& e) {
            cerr << e.what() << endl;
        }

        // Add a new value with error handling
        int valueToAdd;
        cout << "Enter value to add: ";
        cin >> valueToAdd;
        try {
            arrayOps.add(valueToAdd);
            cout << "Value added successfully!" << endl;
        }
        catch (const overflow_error& e) {
            cerr << e.what() << endl;
        }

        // Search for a value in the array
        int valueToFind;
        cout << "Enter value to find: ";
        cin >> valueToFind;
        int foundIndex = arrayOps.find(valueToFind);
        if (foundIndex != -1) {
            cout << "Value found at index: " << foundIndex << endl;
        }
        else {
            cout << "Value not found." << endl;
        }

        // Remove a value from the array
        cout << "Enter index to remove: ";
        cin >> index;
        try {
            arrayOps.remove(index);
            cout << "Value removed successfully!" << endl;
        }
        catch (const out_of_range& e) {
            cerr << e.what() << endl;
        }

    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
