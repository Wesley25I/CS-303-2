#ifndef STACK_H
#define STACK_H

#include <vector>
using namespace std;

// Stack class using vector
class Stack {
private:
    vector<int> stack;  // Vector to store stack elements

public:
    void push(int value);  // Adds an item to the top
    void pop();            // Removes the top item
    int top() const;       // Returns the top item
    bool empty() const;    // Checks if the stack is empty
    double average() const; // Calculates the average of stack elements
};

#endif
