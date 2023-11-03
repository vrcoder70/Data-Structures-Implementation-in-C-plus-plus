#include<iostream> // Include the input-output stream library for C++.

using namespace std; // Use the standard C++ namespace.

class Priority {
    int Front, Rear, Capacity; // Member variables for Priority class: Front, Rear, and Capacity.
    int *Array; // A pointer to an array of integers to store the elements.
public:
    Priority* Create(); // Member function to create a Priority object and return a pointer to it.

    void Insert(Priority* P); // Member function to insert an element into the Priority object pointed to by P.
    void Delete(Priority* P); // Member function to delete an element from the Priority object pointed to by P.
    void Print(Priority* P); // Member function to print the elements in the Priority object pointed to by P.
};