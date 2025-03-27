#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>
using namespace std;

// Template class for the singly linked list
template <typename T>
class Single_Linked_List {
private:
    // Node structure for the linked list
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head; // Pointer to the first node in the list
    size_t num_items; // Number of elements in the list

public:
    
    Single_Linked_List();  // Constructor
    ~Single_Linked_List(); // Destructor

    // Linked List operations
    void push_front(T item);
    void push_back(T item); 
    void pop_front();     
    void pop_back();      
    T front() const;        
    T back() const;        
    bool empty() const;      
    size_t size() const;     
    void insert(size_t index, T item); 
    bool remove(size_t index); 
};

#endif
