#include<iostream>
using namespace std;

class DoubleCircular{
    int Value;              // Data field to store the value of a node in the doubly circular linked list.
    DoubleCircular *Next;   // Pointer to the next node in the doubly circular linked list.
    DoubleCircular *Previous;  // Pointer to the previous node in the doubly circular linked list.
public:
    void Insert();          // Method to insert a new node into the doubly circular linked list.
    void Delete();          // Method to delete a node from the doubly circular linked list.
    void Print();           // Method to print the elements in ascending order.
    void Reverse();         // Method to print the elements in descending order.
};
DoubleCircular *Head = NULL;  // Initialize a global pointer to the head of the doubly circular linked list.

// The code defines a DoubleCircular class for a doubly circular linked list with data members and methods.