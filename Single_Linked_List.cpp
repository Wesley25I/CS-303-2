#include "Single_Linked_List.h"
#include <iostream>
using namespace std;


template <typename T>
Single_Linked_List<T>::Single_Linked_List() : head(nullptr), num_items(0) {}


template <typename T>
Single_Linked_List<T>::~Single_Linked_List() {
    while (head) {
        pop_front();  // Continuously remove nodes from the front
    }
}

// Adds a new node to the front of the list
template <typename T>
void Single_Linked_List<T>::push_front(T item) {
    Node* new_node = new Node(item); 
    new_node->next = head;           // Point new node to the current head
    head = new_node;                 // Update head to new node
    num_items++;                     // Increment size
}

// Adds a new node to the back of the list
template <typename T>
void Single_Linked_List<T>::push_back(T item) {
    Node* new_node = new Node(item); 
    if (!head) {
        head = new_node;  // If the list is empty, make the new node the head
    } else {
        Node* temp = head;
        while (temp->next) {  
            temp = temp->next;
        }
        temp->next = new_node; // Add new node at the end
    }
    num_items++; // Increment size
}

// Removes the first node of the list
template <typename T>
void Single_Linked_List<T>::pop_front() {
    if (head) {
        Node* temp = head;
        head = head->next;  // Move head to the next node
        delete temp;        // Free the memory of the removed node
        num_items--;        // Decrement size
    }
}

// Removes the last node of the list
template <typename T>
void Single_Linked_List<T>::pop_back() {
    if (head) {
        if (!head->next) { // If there's only one node
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->next) {  
                temp = temp->next;
            }
            delete temp->next;  // Delete the last node
            temp->next = nullptr; // Set second-to-last node's next pointer to null
        }
        num_items--; // Decrement size
    }
}

// Returns the first item in the list
template <typename T>
T Single_Linked_List<T>::front() const {
    return head ? head->data : T();  // If list is empty, return default value
}

// Returns the last item in the list
template <typename T>
T Single_Linked_List<T>::back() const {
    if (head) {
        Node* temp = head;
        while (temp->next) {  // Traverse to the last node
            temp = temp->next;
        }
        return temp->data;
    }
    return T();  // Return default value if the list is empty
}

// Checks if the list is empty
template <typename T>
bool Single_Linked_List<T>::empty() const {
    return num_items == 0;
}

// Returns the number of items in the list
template <typename T>
size_t Single_Linked_List<T>::size() const {
    return num_items;
}

// Inserts an item at a specified index
template <typename T>
void Single_Linked_List<T>::insert(size_t index, T item) {
    if (index == 0) {
        push_front(item); // Insert at the front
    } else if (index >= num_items) {
        push_back(item); // Insert at the back if index is out of bounds
    } else {
        Node* new_node = new Node(item); // Create new node
        Node* temp = head;
        for (size_t i = 1; i < index; ++i) {  // Traverse to the (index-1)th node
            temp = temp->next;
        }
        new_node->next = temp->next;  // Insert new node
        temp->next = new_node;
        num_items++;  // Increment size
    }
}

// Removes an item at a specified index
template <typename T>
bool Single_Linked_List<T>::remove(size_t index) {
    if (index >= num_items) return false; // If index is out of bounds, return false

    if (index == 0) {
        pop_front();  // Remove the first node
    } else {
        Node* temp = head;
        for (size_t i = 1; i < index; ++i) {  // Traverse to the (index-1)th node
            temp = temp->next;
        }
        Node* to_delete = temp->next;
        temp->next = temp->next->next;  // Remove the node at the given index
        delete to_delete;
        num_items--;  // Decrement size
    }
    return true;
}

template class Single_Linked_List<int>;
template class Single_Linked_List<std::string>;
