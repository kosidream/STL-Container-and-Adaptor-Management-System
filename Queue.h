#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Queue {
private:
    queue<string> elements; // Private member variable to store elements

public:
    // Adds an element to the back of the queue
    void enqueue(const string& element) {
        elements.push(element);
    }

    // Returns the element at the back of the queue
    string back() {
        return elements.back();
    }

    // Returns the element at the front of the queue
    string front() {
        return elements.front();
    }

    // Removes the element from the front of the queue
    void dequeue() {
        elements.pop();
    }

    // Checks if the queue is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Returns the number of elements in the queue
    int size() const {
        return static_cast<int>(elements.size());
    }

    // Returns the element at the specified index (0-indexed)
    string get(int index) {
        if (index < 0 || index >= elements.size()) {
            throw out_of_range("Index out of range");
        }

        queue<string> tempQueue = elements;

        for (int i = 0; i < index; i++) {
            tempQueue.pop();
        }

        return tempQueue.front();
    }
};

#endif // QUEUE_H
