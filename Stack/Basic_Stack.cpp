#include<iostream> // Include the input-output stream library for C++.

using namespace std; // Use the standard C++ namespace.

class Stack{
    int Top, Capacity; // Declare variables to keep track of the top of the stack and the stack's capacity.
    int *Array; // Declare an integer array to store stack elements.
public:
    Stack* Create(); // Function to create a stack.
    void Push(Stack *S); // Function to push an element onto the stack.
    void Pop(Stack *S); // Function to pop an element from the stack.
    void View(Stack *S); // Function to view the elements in the stack.
};

Stack* Stack::Create(){
    Stack *S = new Stack; // Create a new stack object.
    cout << "Enter Capacity:- ";
    cin >> S->Capacity; // Prompt the user to enter the stack's capacity and store it in the stack object.
    S->Top = -1; // Initialize the top of the stack to -1 (empty).
    S->Array = new int[S->Capacity]; // Allocate memory for the stack array.
    return (S); // Return the created stack object.
};

void Stack::Push(Stack *S){
    if(S->Top != S->Capacity - 1){
        S->Top++; // Increment the top to prepare for the push operation.
        cout << "Enter Data:- ";
        cin >> S->Array[S->Top]; // Read the data and push it onto the stack.
    }
    else
        cout << "Stack is Overflow" << endl; // Stack is full, cannot push more elements.
}

void Stack::Pop(Stack *S){
    if(S->Top != -1){
        cout << "Removed Value:- " << S->Array[S->Top] << endl; // Print the value being removed from the stack.
        S->Top--; // Decrement the top to perform the pop operation.
    }
    else
        cout << "Stack is Empty" << endl; // Stack is empty, cannot pop elements.
}

void Stack::View(Stack *S){
    int top = S->Top; // Copy the top value to a local variable for traversal.
    while(top != -1){
        cout << S->Array[top] << endl; // Print the elements in the stack from top to bottom.
        top--;
    }
}

int main(){
    Stack *C, O; // Declare two stack objects, C and O.
    C = O.Create(); // Create a stack using the Create() function from object O.

    while(1){
        cout << "1: Push" << endl << "2: Pop" << endl << "3: View" << endl << "4: Exit" << endl;
        cout << "Enter Choice:- ";
        int Choice;
        cin >> Choice; // Prompt the user to enter a choice and store it in Choice.

        switch(Choice){
        case 1:
            O.Push(C); // Call the Push() function to push an element onto the stack.
            break;
        case 2:
            O.Pop(C); // Call the Pop() function to pop an element from the stack.
            break;
        case 3:
            O.View(C); // Call the View() function to view the elements in the stack.
            break;
        default:
            return 0; // Exit the program if the choice is not 1, 2, or 3.
        }
    }
}