#include<iostream> // Include the input-output stream library for C++.
#include<stdlib.h> // Include the standard library for various utility functions.
#include<sys/time.h> // Include the system-specific time library for timing measurements.

using namespace std; // Use the standard C++ namespace.

// Function to perform Quick Sort for a portion of an array A with a specified key and index.
void Quick_Sort(int A[], int N, int Key, int I){
    int Left = 0, Right = N, i = I; // Initialize variables for the left, right, and current index.

    while(1){
        for(Right = N; Right > 0; Right--) {
            if(Key >= A[Right]){
                A[i] = A[Right]; // Swap the current element with a larger element.
                A[Right] = Key;
                i = Right;
                break;
            }
        }

        for(Left = 1; Left <= N; Left++) {
            if(Key <= A[Left]){
                A[i] = A[Left]; // Swap the current element with a smaller element.
                A[Left] = Key;
                i = Left;
                break;
            }
        }

        if(Left == Right)
            return;
    }
}

// Function to perform Quick Sort on the entire array A with size N.
void Quick(int A[], int N){
    for(int i = 1; i <= N; i++){
        Quick_Sort(A, N, A[i], i); // Sort a portion of the array using the current element as the key.
    }
}

int main(){
    int N = 100000; // Define the size of the array.
    int A[100000]; // Declare an array of integers.

    for(int i = 1; i <= N; i++){
        A[i] = N - i; // Initialize the array with values in descending order.
    }

    struct timeval t1, t2; // Declare time measurement variables.

    gettimeofday(&t1, NULL); // Record the starting time.

    Quick(A, N); // Call the Quick Sort function to sort the array.

    gettimeofday(&t2, NULL); // Record the ending time.

    // Calculate and print the time taken for sorting in microseconds.
    cout << (t2.tv_sec * 1000000 + t2.tv_usec) - (t1.tv_sec * 1000000 + t1.tv_usec);
}