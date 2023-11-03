#include<iostream> // Include the input-output stream library for C++.

using namespace std; // Use the standard C++ namespace.

int main(){
    int r, c, R = 0; // Declare integers r, c, and R to represent row, column, and non-zero element count.
    cout << "Enter Matrix level:-" << endl;
    cout << "Raw   :-"; cin >> r; // Prompt the user to enter the number of rows and store it in r.
    cout << "Column:-"; cin >> c; // Prompt the user to enter the number of columns and store it in c.
    int A[r][c]; // Declare a 2D array A with the specified number of rows and columns.
    cout << "Enter Values:-" << endl;

    // Loop to read values and count non-zero elements.
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> A[i][j]; // Read a value and store it in the matrix.
            if (A[i][j] != 0) {
                R++; // If the value is non-zero, increment the non-zero element count.
            }
        }
    }

    int B[R][3]; // Declare a 2D array B with R rows and 3 columns to store the sparse matrix.
    R = 0; // Reset the non-zero element count.

    // Loop to create the sparse matrix representation.
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if (A[i][j] != 0){
                B[R][0] = i; // Store the row index.
                B[R][1] = j; // Store the column index.
                B[R][2] = A[i][j]; // Store the non-zero value.
                R++; // Increment the non-zero element count.
            }
        }
    }

    cout << endl << "Sparse Matrix" << endl;

    // Loop to print the sparse matrix.
    for(int i = 0; i < R; i++){
        for(int j = 0; j < 3; j++){
            cout << B[i][j] << " "; // Print the elements of the sparse matrix.
        }
        cout << endl; // Start a new row in the sparse matrix.
    }
}