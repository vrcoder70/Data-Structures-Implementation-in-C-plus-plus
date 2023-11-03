#include<iostream> // Include the input-output stream library for C++.

using namespace std; // Use the standard C++ namespace.

int main(){
    cout << "Number of non-zero elements of 1st Sparse Matrix in Matrix:- ";
    int n;
    cin >> n; // Prompt the user to enter the number of non-zero elements in the first sparse matrix and store it in n.
    int A[n][3]; // Declare a 2D array A to store the first sparse matrix.

    cout << "Format : Raw Column Value" << endl;

    // Loop to read the elements of the first sparse matrix.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> A[i][j];

    cout << "Number of non-zero elements of 2nd Sparse Matrix in Matrix:- ";
    int m;
    cin >> m; // Prompt the user to enter the number of non-zero elements in the second sparse matrix and store it in m.
    int B[m][3]; // Declare a 2D array B to store the second sparse matrix.

    cout << "Format : Raw Column Value" << endl;

    // Loop to read the elements of the second sparse matrix.
    for(int i = 0; i < m; i++)
        for(int j = 0; j < 3; j++)
            cin >> B[i][j];

    cout << "Addition of Matrix:- " << endl;

    // Loop to perform matrix addition and print the result.
    if(m <= n){
        for(int i = 0; i < n; i++){
            if(A[i][0] == B[i][0] && A[i][1] == B[i][1])
                cout << A[i][2] + B[i][2] << endl;
            else if((A[i][0] != B[i][0] || A[i][1] != B[i][1]) && i < m){
                cout << A[i][2] << endl;
                cout << B[i][2] << endl;
            }
            else if((A[i][0] != B[i][0] || A[i][1] != B[i][1]) && i >= m){
                cout << A[i][2] << endl;
            }
        }
    }
    else{
        for(int i = 0; i < m; i++){
            if(A[i][0] == B[i][0] && A[i][1] == B[i][1])
                cout << A[i][2] + B[i][2] << endl;
            else if((A[i][0] != B[i][0] || A[i][1] != B[i][1]) && i < n){
                cout << A[i][2] << endl;
                cout << B[i][2] << endl;
            }
            else if((A[i][0] != B[i][0] || A[i][1] != B[i][1]) && i >= n){
                cout << B[i][2] << endl;
            }
        }
    }

    cout << "Subtraction of Matrix:- " << endl;

    // Loop to perform matrix subtraction and print the result.
    if(m <= n){
        for(int i = 0; i < n; i++){
            if(A[i][0] == B[i][0] && A[i][1] == B[i][1])
                cout << A[i][2] - B[i][2] << endl;
            else if((A[i][0] != B[i][0] || A[i][1] != B[i][1]) && i < m){
                cout << A[i][2] << endl;
                cout << B[i][2] << endl;
            }
            else if((A[i][0] != B[i][0] || A[i][1] != B[i][1]) && i >= m){
                cout << A[i][2] << endl;
            }
        }
    }
    else{
        for(int i = 0; i < m; i++){
            if(A[i][0] == B[i][0] && A[i][1] == B[i][1])
                cout << A[i][2] - B[i][2] << endl;
            else if((A[i][0] != B[i][0] || A[i][1] != B[i][1]) && i < n){
                cout << A[i][2] << endl;
                cout << B[i][2] << endl;
            }
            else if((A[i][0] != B[i][0] || A[i][1] != B[i][1]) && i >= n){
                cout << B[i][2] << endl;
            }
        }
    }
}