#include "Stack.h"
#include "Single_Linked_List.h"
#include <iostream>
using namespace std;

int main() {
    //Tested Stack
    Stack s;
    cout << "Stack created.\n";

    s.push(25);
    s.push(42);
    s.push(67);
    s.push(100);

    cout << "Top of the stack: " << s.top() << endl;
    s.pop();
    cout << "After popping, top: " << s.top() << endl;
    cout << "Average of stack elements: " << s.average() << endl;

    // Tested Linked List
    Single_Linked_List<int> list;
    list.push_front(25);
    list.push_back(42);
    list.push_back(67);
    cout << "Front: " << list.front() << ", Back: " << list.back() << endl;

    list.insert(1, 25);
    list.remove(3);

    cout << "Size of list: " << list.size() << endl;

    return 0;
}
