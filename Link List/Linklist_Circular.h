#include<iostream>
using namespace std;

class Circular{
    int Value;     // Data field to store the value of a node in the circular linked list.
    Circular *Next;  // Pointer to the next node in the circular linked list.
public:
    void Insert();  // Method to insert a new node into the circular linked list.
    void Delete();  // Method to delete a node from the circular linked list.
    void Print();   // Method to print the elements of the circular linked list.
};
Circular *Head = NULL;  // Initialize a global pointer to the head of the circular linked list.

// The code defines a Circular class with data and methods to work with a circular linked list.