#include"Queue.h" // Include a header file named "Queue.h".

using namespace std; // Use the standard C++ namespace.

Queue* Queue::Create(){
    Queue *Q = new Queue; // Declare a pointer to a Queue object and create a new Queue object.
    cout << "Enter Capacity of Queue:- ";
    cin >> Q->Capacity; // Prompt the user to enter the capacity of the queue and store it in the object.
    Q->Array = new int[Q->Capacity]; // Create a dynamic array to store elements based on the specified capacity.
    Q->Front = -1; // Initialize the front of the queue to -1.
    Q->Rear = -1; // Initialize the rear of the queue to -1.
    return (Q); // Return a pointer to the created Queue object.
}

void Queue::Insert(Queue *Q){
    if(Q->Rear != Q->Capacity - 1){
        Q->Rear++; // If the rear is not at the capacity limit, increment it.
        cout << "Enter Number:- ";
        cin >> Q->Array[Q->Rear]; // Prompt the user to enter a number and store it in the array at the rear index.
    }
    else
        cout << "Queue is Full" << endl; // If the rear is at the capacity limit, the queue is full.
}

void Queue::Delete(Queue *Q){
    if(Q->Front != Q->Rear + 1){
        Q->Front++; // If the front is not ahead of the rear, increment it.
        cout << "Deleted Value:- " << Q->Array[Q->Front] << endl; // Display the value being deleted from the front.
        Q->Array[Q->Front] = 0; // Set the value at the front to 0.
    }
    else
        cout << "Queue is Empty" << endl; // If the front is ahead of or equal to the rear, the queue is empty.
}

void Queue::Print(Queue *Q){
    for(int i = 0; i <= Q->Rear; i++) {
        if(Q->Array[i] != 0)
            cout << Q->Array[i] << endl; // Print non-zero elements in the array.
    }
}

int menu(){
    cout << "1:Insert" << endl << "2:Delete" << endl << "3:Print" << endl << "Any to Exit" << endl;
    cout << "Enter Your Choice:- ";
    int Choice;
    cin >> Choice; // Display a menu and prompt the user for their choice.
    return (Choice); // Return the user's choice.
}

int main(){
    Queue *C, O; // Declare a pointer to a Queue object and an object of Queue.
    C = O.Create(); // Create a Queue object and store a pointer to it in C.
    while(1){
        switch(menu()){
        case 1:
            O.Insert(C); // Call the Insert function on the Queue object pointed to by C.
            break;
        case 2:
            O.Delete(C); // Call the Delete function on the Queue object pointed to by C.
            break;
        case 3:
            O.Print(C); // Call the Print function on the Queue object pointed to by C.
            break;
        default:
            return 0; // Exit the program if an invalid choice is made.
        }
    }
}