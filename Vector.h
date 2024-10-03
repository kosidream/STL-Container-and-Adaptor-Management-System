#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Vector {
private:
    vector<string> elements; // Private member variable to store the elements

public:
    // Appends an element to the end of the vector
    void append(const string& element) {
        elements.push_back(element);
    }

    // Inserts an element at a specified index
    void insert(int index, const string& element) {
        elements.insert(elements.begin() + index, element);
    }

    // Retrieves the element at a given index
    string get(int index) {
        return elements[index];
    }

    // Sorts the elements in ascending order
    void sort() {
        ::sort(elements.begin(), elements.end());
    }

    // Removes all elements from the vector
    void clear() {
        elements.clear();
    }

    // Returns the number of elements in the vector
    int size() const {
        return static_cast<int>(elements.size());
    }

    // Checks if the vector is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Checks if a specific element exists in the vector
    bool containsElement(const std::string& element) {
        return find(elements.begin(), elements.end(), element) != elements.end();
    }

    // Deletes a specific element from the vector
    void deleteElement(const string& element) {
        elements.erase(remove(elements.begin(), elements.end(), element), elements.end());
    }

    // Deletes the element at a specific index
    void deleteElementAt(int index)
    {
        // Throws an exception if the index is out of range
        if (index < 0 || index >= elements.size()) {
            throw out_of_range("Index out of range");
        }

        elements.erase(elements.begin() + index);
    }
};

#endif 
