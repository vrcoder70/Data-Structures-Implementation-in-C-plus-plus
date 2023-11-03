#include<iostream>
using namespace std;

class Link{
    int Value;           // Data field to store the value of a node in the linked list.
    Link *Next;          // Pointer to the next node in the linked list.
public:
    void Insertion1();  // Method to insert a new node at the end of the linked list.
    void Insertion2();  // Method to insert a new node at the beginning of the linked list.
    void Insertion3();  // Method to insert a new node at an arbitrary position in the linked list.
    void Delete1();     // Method to delete the last element in the linked list.
    void Delete2();     // Method to delete the first element in the linked list.
    void Delete3();     // Method to delete a node at an arbitrary position in the linked list.
    void Print();       // Method to print the elements in the linked list.
    void Frequency();   // Method to calculate the frequency of a specified element.
    void Sort();        // Method to sort the elements in the linked list.
};
Link *Head = NULL;       // Initialize a global pointer to the head of the linked list.

// The code defines a Link class for a linked list with data members and methods.