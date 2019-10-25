/*
Write C++ program for sparse matrix realization and perform following operations on it:
Fast Transpose 
addition of two matrices
*/
#include <iostream>
using namespace std;
int main()
{
    int row1, col1, row2, col2, i, j, count_0 = 0;

    //GETTING FIRST MATRIX
    cout << "Enter the number of rows and columns: \n";
    cin >> row1 >> col1;
    int arr[row1][col1];
    cout << "Enter the elements of the matrix: \n";
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                count_0++;
        }
    }

    //VALIDITY OF SPARSE MATRIX
    if (count_0 >= (row1 * col1) / 2)
        cout << "This is a sparse matrix\n";
    else
        cout << "This is NOT a sparse matrix\n";

    //DISPLAYING FIRST SPARSE MATRIX
    cout << "ROW\t\t\tCOLUMN\t\t\tVALUE\n";
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            if (arr[i][j] != 0)
                cout << i << "\t\t\t" << j << "\t\t\t" << arr[i][j] << "\n";
        }
    }

    //FAST TRANSPOSE
    cout << "ROW\t\t\tCOLUMN\t\t\tVALUE\n";
    for (i = 0; i < col1; i++)
    {
        for (j = 0; j < row1; j++)
        {
            if (arr[j][i] != 0)
                cout << i << "\t\t\t" << j << "\t\t\t" << arr[j][i] << "\n";
        }
    }

    //GETTING SECOND MATRIX
    cout << "Enter the number of rows and columns: \n";
    cin >> row2 >> col2;
    int arr2[row2][col2];
    cout << "Enter the elements of the matrix: \n";
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            cin >> arr2[i][j];
        }
    }

    //DISPLAYING SECOND SPARSE MATRIX
    cout << "ROW\t\t\tCOLUMN\t\t\tVALUE\n";
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            if (arr2[i][j] != 0)
                cout << i << "\t\t\t" << j << "\t\t\t" << arr2[i][j] << "\n";
        }
    }
    return 0;
}