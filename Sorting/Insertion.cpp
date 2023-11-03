#include<iostream> // Include the input-output stream library for C++.

using namespace std; // Use the standard C++ namespace.

int main(){
    int K; // Declare an integer K to store the number of elements.
    cout << "Enter Number:- ";
    cin >> K; // Prompt the user to enter the number of elements and store it in K.
    int *A = new int[K]; // Create a dynamic array of integers with a size of K.
    cout << "Enter " << K << " Number:-" << endl;

    // Loop to read and sort K numbers in ascending order.
    for(int i = 0; i < K; i++){
        cin >> A[i]; // Read an integer from the user and store it in the array A.
        int k, T, j = 0;
        T = A[i]; // Store the current element in T, which will be inserted into the sorted section.
        k = i; // Store the current index in k.

        // Loop to find the correct position to insert the current element.
        while(j < i){
            if(A[j] > A[i]){
                // Shift elements to make space for the new element.
                while(k >= j){
                    A[k] = A[k - 1];
                    k--;
                }
                A[j] = T; // Insert the current element in its correct position.
                break;
            }
            j++;
        }
    }

    // Loop to print the sorted array A.
    for(int i = 0; i < K; i++)
        cout << A[i] << " ";
    cout << endl;
}