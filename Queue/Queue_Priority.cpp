#include"Priority.h" // Include a header file named "Priority.h".

using namespace std; // Use the standard C++ namespace.

Priority* Priority::Create(){
    Priority *P; // Declare a pointer to a Priority object.
    P=new Priority(); // Create a new Priority object and assign it to the pointer.
    cout<<"Enter Capacity of Priority Queue:- ";
    cin>>P->Capacity; // Prompt the user to enter the capacity of the priority queue and store it in the object.
    P->Front=-1; // Initialize the front of the queue to -1.
    P->Rear=-1; // Initialize the rear of the queue to -1.
    P->Array=new int[P->Capacity]; // Create a dynamic array to store elements based on the specified capacity.
    return (P); // Return a pointer to the created Priority object.
}

void Priority::Insert(Priority* P){
    if(P->Rear==-1) {
        P->Rear=0; // If the rear is -1, set it to 0.
    }

    if(P->Rear!=P->Capacity){
        cout<<"Enter Number:- ";
        cin>>P->Array[P->Rear]; // Prompt the user to enter a number and store it in the array at the rear index.

        int k, T, j=0;
        T=P->Array[P->Rear]; // Store the newly entered number in T.
        k=P->Rear; // Store the rear index in k.

        while(j < P->Rear){
            if(P->Array[j] > P->Array[P->Rear]){
                while(k >= j){
                    P->Array[k]=P->Array[k-1]; // Shift elements to make space for the new number.
                    k--;
                }
                P->Array[j]=T; // Insert the new number in the appropriate position.
                break;
            }
            j++;
        }
        P->Rear++; // Increment the rear index.
    }
    else{
        cout<<"Queue is Full. "; // If the rear is equal to the capacity, the queue is full.
    }
}

void Priority::Delete(Priority* P){
    if(P->Front==-1)
        P->Front=0; // If the front is -1, set it to 0.

    if(P->Front!=P->Rear){
        cout<<"Deleted Value:- "<<P->Array[P->Front]<<endl; // Display the value being deleted from the front.
        P->Array[P->Front]=0; // Set the value at the front to 0.
        P->Front++; // Increment the front index.
    }
    else
        cout<<"Queue is Empty. "; // If front is equal to rear, the queue is empty.
}

void Priority::Print(Priority* P){
    int F=0; // Initialize a variable for iterating through the array.
    while(F!=P->Rear){
        if(P->Array[F]!=0)
            cout<<P->Array[F]<<" "; // Print non-zero elements in the array.
        F++;
    }
    cout<<endl; // Print a newline after printing the elements.
}

int menu(){
    cout<<"1:Insert"<<endl<<"2:Delete"<<endl<<"3:Print"<<endl<<"Enter any to Exit:- ";
    int Choice; cin>>Choice; // Display a menu and prompt the user for their choice.
    return (Choice); // Return the user's choice.
}

int main(){
    Priority *C,O; // Declare a pointer to a Priority object and an object of Priority.
    C=O.Create(); // Create a Priority object and store a pointer to it in C.
    while(1){
        switch(menu()){
        case 1:
            O.Insert(C); // Call the Insert function on the Priority object pointed to by C.
            break;
        case 2:
            O.Delete(C); // Call the Delete function on the Priority object pointed to by C.
            break;
        case 3:
            O.Print(C); // Call the Print function on the Priority object pointed to by C.
            break;
        default:
            return 0; // Exit the program if an invalid choice is made.
        }
    }
}