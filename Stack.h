#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Stack {
private:
    stack<string> elements; // Private member variable to store elements

public:
    // Pushes an element onto the top of the stack
    void push(const string& element) {
        elements.push(element);
    }

    // Returns the top element of the stack
    string top() {
        return elements.top();
    }

    // Removes the top element from the stack
    void pop() {
        elements.pop();
    }

    // Checks if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Returns the number of elements in the stack
    int size() const {
        return static_cast<int>(elements.size());
    }

    // Returns the element at the specified index (0-indexed)
    string get(int index) {
        stack<string> tempStack = elements;
        int count = 0;

        while (!tempStack.empty()) {
            if (count == index) {
                return tempStack.top();
            }

            tempStack.pop();
            count++;
        }

        // Throws an exception if the index is out of range
        throw out_of_range("Index out of range");
    }
};

#endif // STACK_H
