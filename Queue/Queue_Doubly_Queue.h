#include<iostream>
using namespace std;

class Priority {
    int Front, Rear, Capacity; // Member variables for Priority class: Front, Rear, and Capacity.
    int *Array; // A pointer to an array of integers to store the elements.
public:
    Priority* Create(); // Member function to create a Priority object and return a pointer to it.

    void Insert(Priority* P); // Member function to insert an element into the Priority object pointed to by P.
    void Insert1(Priority* P); // Member function to insert an element into the Priority object pointed to by P.

    void Delete(Priority* P); // Member function to delete an element from the Priority object pointed to by P.
    void Delete1(Priority* P); // Member function to delete an element from the Priority object pointed to by P.

    void Print(Priority* P); // Member function to print the elements in the Priority object pointed to by P.
};

