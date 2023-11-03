#include "Circular.h" // Include the Circular class header file.

void Circular::Insert(){
    Circular *New, *Node;
    New = new Circular; // Create a new Circular object.
    cout << "Enter Number:- ";
    cin >> New->Value; // Read a number from the user and store it in the Value field of the new object.
    New->Next = NULL;
    if (!Head)
        Head = New; // If the Head is null, set it to the new object.
    else {
        Node = Head; // Initialize Node to the Head of the circular linked list.
        if (Node->Next == NULL) {
            Node->Next = New; // If there's only one element in the list, connect it to the new element.
            New->Next = Head;
        }
        else {
            while (Node->Next != Head)
                Node = Node->Next; // Traverse the list to find the last node.
            Node->Next = New; // Connect the last node to the new node.
            New->Next = Head; // Make the new node circular.
        }
    }
}

void Circular::Delete(){
    Circular *Node, *D;
    Node = Head; // Initialize Node to the Head of the circular linked list.
    int key;
    cout << "Enter A Number You want To delete:- ";
    cin >> key; // Read the number to be deleted from the user.
    while (Node->Next->Value != key)
        Node = Node->Next; // Traverse the list to find the node with the specified value.
    D = Node->Next; // Store the node to be deleted in D.
    Node->Next = Node->Next->Next; // Update the pointers to skip the node to be deleted.
    delete D; // Deallocate the memory of the deleted node.
}

void Circular::Print(){
    Circular *P;
    P = Head; // Initialize P to the Head of the circular linked list.
    while (P->Next != Head) {
        cout << P->Value << endl; // Print the value of the current node.
        P = P->Next; // Move to the next node in the list.
    }
    cout << P->Value << endl; // Print the value of the last node in the list.
}

int menu(){
    cout << "1: Insertion" << endl << "2: Deletion" << endl << "3: Print" << endl << "4: Exit :- ";
    int i;
    cin >> i; // Read the user's choice from the menu.
    return i;
}

int main(){
    Circular O; // Create a Circular object.
    while (1) {
        switch (menu()) {
        case 1:
            O.Insert(); // Call the Insert method on the Circular object.
            break;
        case 2:
            O.Delete(); // Call the Delete method on the Circular object.
            break;
        case 3:
            O.Print(); // Call the Print method on the Circular object.
            break;
        case 4:
            return 0; // Exit the program.
        default:
            cout << "Invalid" << endl; // Handle an invalid menu choice.
        }
    }
}