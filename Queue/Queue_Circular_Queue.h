#include<iostream>
using namespace std;

class Circular_Queue {
    int Front, Rear, Capacity;  // Variables to manage the circular queue.
    int *Array;  // Pointer to an array for storing queue elements.

public:
    Circular_Queue* Create();
    // Function to create a new Circular_Queue object and initialize its properties.

    void Insert(Circular_Queue* CQ);
    // Function to insert an element into the circular queue.

    void Delete(Circular_Queue* CQ);
    // Function to delete an element from the circular queue.

    void Print(Circular_Queue* CQ);
    // Function to print the elements of the circular queue.
};
