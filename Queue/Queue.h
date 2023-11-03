#include<iostream> // Include the input-output stream library for C++.

using namespace std; // Use the standard C++ namespace.

class Queue {
    int Front, Rear, Capacity; // Member variables for the Queue class: Front, Rear, and Capacity.
    int *Array; // A pointer to an array of integers to store the elements.
public:
    Queue* Create(); // Member function to create a Queue object and return a pointer to it.

    void Insert(Queue *Q); // Member function to insert an element into the Queue object pointed to by Q.
    void Delete(Queue *Q); // Member function to delete an element from the Queue object pointed to by Q.
    void Print(Queue *Q); // Member function to print the elements in the Queue object pointed to by Q.
};
