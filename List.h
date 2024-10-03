#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class List {
private:
    list<string> elements; // Private member variable to store elements

public:
    // Adds an element to the front or back of the list based on the addToFront parameter
    void add(const string& element, bool addToFront) {
        if (addToFront) {
            elements.push_front(element);
        }
        else {
            elements.push_back(element);
        }
    }

    // Inserts an element at the specified index
    void insert(int index, const string& element) {
        auto it = elements.begin();
        advance(it, index);
        elements.insert(it, element);
    }

    // Returns the element at the specified index (0-indexed)
    string get(int index) {
        auto it = elements.begin();
        advance(it, index);
        return *it;
    }

    // Sorts the elements in the list
    void sort() {
        elements.sort();
    }

    // Clears all elements from the list
    void clear() {
        elements.clear();
    }

    // Returns the number of elements in the list
    size_t size() const {
        return elements.size();
    }

    // Checks if the list is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Checks if the list contains a specific element
    bool containsElement(const string& element) {
        return find(elements.begin(), elements.end(), element) != elements.end();
    }

    // Deletes all occurrences of a specific element from the list
    void deleteElement(const string& element) {
        elements.erase(remove(elements.begin(), elements.end(), element), elements.end());
    }
};

#endif // LIST_H
