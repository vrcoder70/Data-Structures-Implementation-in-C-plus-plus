#include"DoubleCircular.h"  // Include the DoubleCircular class header file.

void DoubleCircular::Insert(){
    DoubleCircular *New, *Node;
    New = new DoubleCircular; // Create a new DoubleCircular object.
    cout << "Enter Value:- ";
    cin >> New->Value; // Read a value from the user and store it in the Value field of the new object.
    New->Next = NULL;
    New->Previous = NULL;
    if (!Head)
        Head = New; // If the Head is null, set it to the new object.
    else {
        Node = Head; // Initialize Node to the Head of the double circular linked list.
        if (Node->Next != Head) {
            Node->Next = New; // If there's more than one element in the list, connect the last element to the new element.
            Node->Previous = New;
            New->Previous = Head;
            New->Next = Head;
        }
        else {
            while (Node->Next != Head)
                Node = Node->Next; // Traverse the list to find the last node.
            Node->Next = New; // Connect the last node to the new node.
            New->Next = Head;
            New->Previous = Node;
            Head->Previous = New;
        }
    }
}

void DoubleCircular::Delete(){
    int key;
    cout << "Enter Value that you want to Delete:- ";
    cin >> key; // Read the value to be deleted from the user.
    DoubleCircular *D, *Node;
    Node = Head;
    while (Node->Next->Value != key)
        Node = Node->Next; // Traverse the list to find the node with the specified value.
    D = Node->Next; // Store the node to be deleted in D.
    Node->Next = Node->Next->Next; // Update the pointers to skip the node to be deleted.
    Node->Next->Previous = Node;
    delete D; // Deallocate the memory of the deleted node.
    return;
}

void DoubleCircular::Print(){
    DoubleCircular *Node;
    Node = Head; // Initialize Node to the Head of the double circular linked list.
    while (Node->Next != Head) {
        cout << Node->Value << endl; // Print the value of the current node.
        Node = Node->Next; // Move to the next node in the list.
    }
    cout << Node->Value << endl; // Print the value of the last node in the list.
}

void DoubleCircular::Reverse(){
    DoubleCircular *Node;
    Node = Head; // Initialize Node to the Head of the double circular linked list.
    while (Node->Previous != Head) {
        cout << Node->Previous->Value << endl; // Print the value of the previous node in descending order.
        Node = Node->Previous; // Move to the previous node in the list.
    }
    cout << Node->Previous->Value << endl; // Print the value of the last node in descending order.
}

int menu(){
    cout << "1: Insert" << endl << "2: Delete" << endl << "3: Print in Ascending Order" << endl;
    cout << "4: Print in Descending Order" << endl << "5: Exit :-";
    int i;
    cin >> i; // Read the user's choice from the menu.
    return i;
}

int main(){
    DoubleCircular O; // Create a DoubleCircular object.
    while (1) {
        switch (menu()) {
        case 1:
            O.Insert(); // Call the Insert method on the DoubleCircular object.
            break;
        case 2:
            O.Delete(); // Call the Delete method on the DoubleCircular object.
            break;
        case 3:
            O.Print(); // Call the Print method to display elements in ascending order.
            break;
        case 4:
            O.Reverse(); // Call the Reverse method to display elements in descending order.
            break;
        case 5:
            exit(0); // Exit the program.
        default:
            cout << endl << "Invalid" << endl; // Handle an invalid menu choice.
        }
    }
}