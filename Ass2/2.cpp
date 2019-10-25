/*
Write C++ program for storing matrix. Write functions for
Check whether given matrix is upper triangular or not
Compute summation of diagonal elements 
Compute transpose of matrix 
Add, subtract and multiply two matrices  
Check saddle point is present or not.
*/
#include<iostream>
using namespace std;

int main()
{
    int row1, col1, row2, col2, i, j, k;

    //first matrix
    cout << "Enter the number of rows and columns";
    cin >> row1 >> col1;
    int arr1[row1][col1];
    cout << "\nEnter the elements: ";
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            cin >> arr1[i][j];
        }
    }

    //displaying 1st matrix
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            cout<< arr1[i][j]<<" ";
        }
        cout<<endl;
    }

    //upper transpose matrix
    int flag = 0;
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr1[i][j] != 0)
                flag = 1;
        }
    }
    if (flag == 1)
        cout << "\nThis matrix is not a upper triangular matrix. ";
    else
    {
        cout << "\nThis matrix is a upper triangular matrix. ";
    }

    //sum of diagonal elements
    int diagonal_Sum = 0;
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            if (i == j)
                diagonal_Sum += arr1[i][j];
        }
    }
    cout << "\nThe sum of the diagonal elements is: " << diagonal_Sum<<endl;

    //transpose of matrix
    cout<<"\nTranspose of the matrix\n";
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            cout << arr1[j][i] << " ";
        }
        cout << endl;
    }

    //saadle point in first matrix
    int minn, maxx, l=0,check=0; 
    for (int i = 0; i < row1; i++)
    {
        minn = arr1[i][0];
        for (int j = 1; j < col1; j++)
        {
            minn = min(minn, arr1[i][j]);
            if (minn != arr1[i][0])
                l = j;
        }

        maxx = arr1[0][l];
        for (k = 1; k < row1; k++)
        {
            maxx = max(maxx, arr1[k][l]);
        }
        if (maxx == minn){
            cout << "\nSaddle Point found in first matrix : " << maxx;
            check=1;
        }
    }
    if(check==0)
        cout<<"\nSaddle point not present.";


    //second matrix
    cout << "\nEnter the number of rows and columns";
    cin >> row2 >> col2;
    int arr2[row2][col2];
    cout << "\nEnter the elements: ";
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            cin >> arr2[i][j];
        }
    }

    //adding matrices arr1[][] and arr2[][]
    cout << "\nAddition of two matrices" << endl;
    if(row1==row2 && col1==col2){
        int sum[row1][col1];
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col1; j++)
            {
                sum[i][j]=arr1[i][j]+arr2[i][j];
                cout<<sum[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"The addition of these matrices is not possible"<<endl;
    }

    //subtracting matrices arr1[][] and arr2[][]
    cout << "\nSubtraction of two matrices"<<endl;
    if (row1 == row2 && col1 == col2)
    {
        int diff[row1][col1];
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col1; j++)
            {
                diff[i][j] = arr1[i][j] - arr2[i][j];
                cout << diff[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "The subtraction of these matrices is not possible" << endl;
    }

    //multiplying matrices arr1[][] and arr2[][]
    cout << "\nMultiplication of two matrices"<<endl;
    if (col1 == row2)
    {
        int prod[row1][col2];
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col2; j++)
            {
                int SUM=0;
                for(k=0; k<col1; k++){
                    SUM += (arr1[i][k]*arr2[k][j]);
                }
                prod[i][j] = SUM;
                cout<<prod[i][j]<<" ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "The multiplication of these matrices is not possible" << endl;
    }
}