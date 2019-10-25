/*
Write C++ program for sparse matrix realization and perform following operations on it:
Fast Transpose 
addition of two matrices
*/
#include <iostream>
using namespace std;
int main()
{
    int row, col, i, j,count_0=0;
    cout << "Enter the number of rows and columns: \n";
    cin >> row >> col;
    int arr[row][col];
    cout << "Enter the elements of the matrix: \n";
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==0)
                count_0++;
        }
    }

    //VALIDITY OF SPARSE MATRIX
    if(count_0>=(row*col)/2)
        cout<<"This is a sparse matrix\n";
    else
        cout << "This is NOT a sparse matrix\n";

    //DISPLAYING SPARSE MATRIX
    cout<<"ROW\t\t\tCOLUMN\t\t\tVALUE\n";
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(arr[i][j]!=0)
                cout<<i<<"\t\t\t"<<j<<"\t\t\t"<<arr[i][j]<<"\n";
        }
    }

    
    return 0;
}