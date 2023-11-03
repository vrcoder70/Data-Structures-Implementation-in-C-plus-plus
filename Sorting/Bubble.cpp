#include<iostream> // Include the input-output stream library for C++.

using namespace std; // Use the standard C++ namespace.

int main(){
    int K, *A; // Declare an integer K and a pointer to an integer array A.
    cout << "Enter Number:- ";
    cin >> K; // Prompt the user to enter a number and store it in K.
    A = new int[K]; // Create a dynamic array of integers with a size of K.
    cout << "Enter " << K << " Numbers:- " << endl;

    // Loop to read K numbers into the array A.
    for(int i = 0; i < K; i++)
        cin >> A[i];

    // Bubble sort algorithm to sort the elements in the array A in ascending order.
    for(int round = 1; round <= K; round++)
        for(int i = 0; i < K - round; i++)
            if(A[i] > A[i + 1]){
                int T;
                T = A[i];
                A[i] = A[i + 1];
                A[i + 1] = T;
            }

    // Loop to print the sorted elements in the array A.
    for(int i = 0; i < K)
        cout << A[i] << " ";
    cout << endl;
}