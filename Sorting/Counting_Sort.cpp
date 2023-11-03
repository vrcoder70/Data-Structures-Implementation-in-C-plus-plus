#include<iostream> // Include the input-output stream library for C++.

using namespace std; // Use the standard C++ namespace.

// Function to perform counting sort on an array A of size N with a maximum element value of Max.
void countsort(int A[], int N, int Max){
    int C[Max], B[N]; // Create arrays C and B to store count and result.
    
    // Initialize the count array C to zeros.
    for(int i = 1; i <= Max; i++)
        C[i] = 0;

    // Count the occurrences of each element in array A and store in C.
    for(int i = 1; i <= N; i++)
        C[A[i]]++;

    // Calculate cumulative counts in C.
    for(int i = 2; i <= Max; i++)
        C[i] = C[i] + C[i-1];

    // Build the sorted array B using the counts in C.
    for(int i = N; i > 0; i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

    // Print the sorted array B.
    for(int i = 1; i <= N; i++)
        cout << B[i] << " ";
}

int main(){
    int N;
    cout << "Size:- ";
    cin >> N; // Prompt the user to enter the size of the array.
    int A[N];
    for(int i = 1; i <= N; i++)
        cin >> A[i]; // Read N integers from the user and store them in array A.
    int Max = A[1];
    
    // Find the maximum element value in array A.
    for(int i = 2; i <= N; i++){
        if(Max < A[i])
            Max = A[i];
    }
    
    // Call the countsort function to sort the array A.
    countsort(A, N, Max);
}