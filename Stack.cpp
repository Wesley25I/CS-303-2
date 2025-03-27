#include "Stack.h"
#include <stdexcept>
#include <numeric>
using namespace std;

// Adds an item to the top of the stack
void Stack::push(int value) {
    stack.push_back(value);  // Add the element to the vector
}

// Removes the top item from the stack
void Stack::pop() {
    if (empty()) throw underflow_error("Stack is empty.");
    stack.pop_back();  // Remove the last element from the vector
}

// Returns the top item of the stack
int Stack::top() const {
    if (empty()) throw underflow_error("Stack is empty.");
    return stack.back();  // Return the last element of the vector
}

// Checks if the stack is empty
bool Stack::empty() const {
    return stack.empty();  // Return true if vector is empty
}

// Calculates the average of the stack elements
double Stack::average() const {
    if (empty()) throw underflow_error("Stack is empty.");
    return accumulate(stack.begin(), stack.end(), 0) / static_cast<double>(stack.size());  // Calculate the average
}
