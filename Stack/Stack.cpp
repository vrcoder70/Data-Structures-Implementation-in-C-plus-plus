#include<iostream> // Include the input-output stream library for C++.

using namespace std; // Use the standard C++ namespace.

class Stack{
    int Top, Capacity; // Declare variables to keep track of the top of the stack and the stack's capacity.
    int *Array; // Declare an integer array to store the stack elements.
public:
    Stack* Create(int Cap); // Function to create a stack with a specified capacity.
    void Push(Stack* S); // Function to push digits onto the stack.
    int Pop(Stack* S); // Function to pop a digit from the stack.
    int Full(Stack* S); // Function to check if the stack is full.
    int Empty(Stack* S); // Function to check if the stack is empty.
};

int Stack::Full(Stack* S){
    if(S->Top == S->Capacity - 1)
        return 1; // The stack is full.
    else
        return 0; // The stack is not full.
}

int Stack::Empty(Stack* S){
    if(S->Top == -1)
        return 1; // The stack is empty.
    else
        return 0; // The stack is not empty.
}

Stack* Stack::Create(int Cap){
    Stack *S = new Stack; // Create a new stack object.
    S->Top = -1; // Initialize the top of the stack to -1 (empty).
    S->Capacity = Cap; // Set the stack's capacity to the specified value.
    S->Array = new int[S->Capacity]; // Allocate memory for the integer array.
    return S; // Return the created stack object.
}

void Stack::Push(Stack* S){
    int Digit; // Declare an integer variable to store the input digit.
    cout << "Enter -1 when finished" << endl;
    cout << "Enter Digit One by One:- ";

    while(S->Top != S->Capacity - 1){
        cin >> Digit; // Read a digit from the user.
        if(Digit == -1)
            break; // Exit the loop if -1 is entered.
        else
            S->Array[++S->Top] = Digit; // Push the digit onto the stack.
    }

    if(S->Top == S->Capacity - 1)
        cout << "Overflow" << endl; // Stack is full, and further digits cannot be pushed.
}

int Stack::Pop(Stack* S){
    int D; // Declare an integer variable to store the popped digit.
    if(S->Top == -1){
        return 0; // Stack is empty, return 0 to indicate no digit to pop.
    }
    else{
        D = S->Array[S->Top--]; // Pop the top digit from the stack.
        return D; // Return the popped digit.
    }
}

int main(){
    Stack *S1, *S2, *A, O; // Declare stack objects for the first number (S1), second number (S2), and the result (A).
    int Cap, A1, A2, i = 0; // Declare integer variables for capacity, digits, and a counter.

    cout << "Enter Digits Binary Number:- ";
    cin >> Cap; // Prompt the user to enter the number of digits in the binary numbers and store it in Cap.

    S1 = O.Create(Cap); // Create a stack for the first binary number.
    S2 = O.Create(Cap); // Create a stack for the second binary number.
    A = O.Create(Cap + 1); // Create a stack for the result, which may have an additional digit.
    int A3[Cap + 1]; // Declare an array to store the sum of the digits.

    cout << "Enter 1st Number:- ";
    O.Push(S1); // Push the binary digits of the first number onto stack S1.

    cout << "Enter 2nd Number:- ";
    O.Push(S2); // Push the binary digits of the second number onto stack S2.

    while(!O.Empty(S1) || !O.Empty(S2)){
        A1 = O.Pop(S1); // Pop a digit from the first stack.
        A2 = O.Pop(S2); // Pop a digit from the second stack.
        A3[i++] = A1 + A2; // Calculate the sum of the popped digits and store it in A3.
    }
}
