/*
a)Write C++ program to store roll numbers of student in array who attended training program in random order.
Write function for searching whether particular student attended training program or not using linear search and sentinel search. 
b) Write C++ program to store roll numbers of student array who attended training program in sorted order.
Write function for searching whether particular student attended training program or not using
binary search and Fibonacci search.
*/
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
class SEARCH
{
public:
    int size;
    int arr[MAX];
    void linearSearch(int, int);
    void sentinelSearch(int, int);
    void binarySearch(int, int);
    void fibonacciSearch(int, int);
};

void SEARCH::linearSearch(int n, int find)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == find)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "\nRoll number present";
    else
        cout << "\nRoll number NOT present";
}

void SEARCH::sentinelSearch(int n, int find)
{
    int index;
    int last = arr[n - 1];
    arr[n - 1] = find;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == find)
        {
            index = i;
            break;
        }
    }
    if (index == n - 1 && last != find)
        cout << "\nRoll number NOT present";
    else
        cout << "\nRoll number present";
}

void SEARCH::binarySearch(int n, int find)
{
    sort(arr,arr+n);            //binary search works only for sorted arrays
    int first = 0, last = n - 1;
    int middle = (first + last) / 2;
    int flag = 0;
    while (first <= last)
    {
        if (arr[middle] == find)
        {
            flag = 1;
            break;
        }
        else if(arr[middle]>find){
            last = middle - 1;
        }
        else if(arr[middle]<find){
            first = middle + 1;
        }
        middle = (first + last) / 2;
    }
    if(flag==1)
        cout << "\nRoll number present";
    else
        cout << "\nRoll number NOT present";
}

void SEARCH::fibonacciSearch(int n, int find)
{
    sort(arr,arr+n);            //fibonacci search works only for sorted arrays
    int fib2 = 0, fib1 = 1;
    int fib = fib1 + fib2;
    while (fib < n)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }
    int offset = -1;
    while (fib > 1)
    {
        int i = min(offset + fib2, n - 1);
        if (arr[i] < x)
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > x)
        {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else
        {
            cout << x << " roll number is present at the training program. \n";
            goto hell;
        }
    }
    if (fib1 && arr[offset + 1] == x)
    {
        cout << x << " roll number is present at the training program. \n";
        goto hell;
    }
    else
    {
        cout << x << " roll number is NOT present at the training program. \n";
    }

hell:
    cout << endl;
}

int main()
{
    SEARCH s;
    int n, choice, find;
    cout << "Enter the number of students present: ";
    cin >> n;
    cout << "\nEnter roll numbers of " << n << " students: ";
    for (int i = 0; i < n; i++)
    {
        cin >> s.arr[i];
    }
up:
    cout << "\nSORTING";
    cout << "\n1. Linear Search";
    cout << "\n2. Sentinel Search";
    cout << "\n3. Binary Search";
    cout << "\n4. Fibonacci Search";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter the roll number you want to find: ";
        cin >> find;
        s.linearSearch(n, find);
        break;
    case 2:
        cout << "Enter the roll number you want to find: ";
        cin >> find;
        s.sentinelSearch(n, find);
        break;
    case 3:
        cout << "Enter the roll number you want to find: ";
        cin >> find;
        s.binarySearch(n, find);
        break;
    case 4:
        cout << "Enter the roll number you want to find: ";
        cin >> find;
        s.fibonacciSearch(n, find);
        break;
    default:
        cout << "\nWrong choice entered";
    }
    cout << "\nDo you want to continue(y/n): ";
    char yn;
    cin >> yn;
    if (yn == 'y')
        goto up;
    else
        return 0;
}