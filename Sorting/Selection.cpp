#include<iostream> // Include the input-output stream library for C++.

using namespace std; // Use the standard C++ namespace.

// Function to find the index of the minimum element in an array A from index K to N.
int MIN(int A[], int K, int N){
    int LOC, MIN; // Declare variables to store the location (index) and minimum value.
    MIN = A[K]; // Initialize MIN with the value at index K.
    LOC = K; // Initialize LOC with the index K.

    // Loop to find the minimum element and its index from K to N.
    for(int j = K; j < N; j++){
        if(MIN > A[j]){
            MIN = A[j]; // Update MIN if a smaller element is found.
            LOC = j; // Update LOC to store the index of the minimum element.
        }
    }
    return LOC; // Return the index of the minimum element.
}

int main(){
    cout << "Enter Number:- ";
    int N; cin >> N; // Prompt the user to enter the number of elements and store it in N.
    int A[N]; // Declare an array of integers with size N.
    cout << "Enter " << N << " Numbers:-" << endl;

    // Loop to read N integers from the user and store them in array A.
    for(int i = 0; i < N; i++)
        cin >> A[i];

    // Selection sort algorithm to sort the array A in ascending order.
    for(int k = 0; k < N - 1; k++){
        int LOC = MIN(A, k, N); // Find the index of the minimum element from index k to N.
        int Temp = A[k];
        A[k] = A[LOC]; // Swap the current element with the minimum element.
        A[LOC] = Temp;
    }

    // Loop to print the sorted array A.
    for(int i = 0; i < N; i++)
        cout << A[i] << " ";
}