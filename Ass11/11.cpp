/*
a)Write C++ program to store roll numbers of student in array who attended training program in random order.
Write function for searching whether particular student attended training program or not using linear search and sentinel search. 
b) Write C++ program to store roll numbers of student array who attended training program in sorted order.
Write function for searching whether particular student attended training program or not using
binary search and Fibonacci search.
*/
#include <iostream>
#define MAX 100
using namespace std;
class SORT
{
public:
    int size;
    int arr[MAX];
    void linearSearch(int, int);
    void sentinelSearch(int, int);
    void binarySeach(int, int);
};

void SORT::linearSearch(int n, int find)
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

void SORT::sentinelSearch(int n, int find)
{
    int index;
    int last = arr[n-1];
    arr[n-1] = find;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == find)
        {
            index = i;
            break;
        }
    }
    if (index == n-1 && last!=find)
        cout << "\nRoll number NOT present";
    else
        cout << "\nRoll number present";
}

void SORT::binarySeach(int n, int find)
{
    
}

int main()
{
    SORT s;
    int n, choice, find;
    cout << "Enter the number of students present: ";
    cin >> n;
    cout << "\nEnter roll numbers of " << n << " students: ";
    for (int i = 0; i < n; i++)
    {
        cin >> s.arr[i];
    }
    hell:
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
        s.binarySeach(n, find);
        break;
    default:
        cout<<"\nWrong choice entered";
    }
    cout<<"\nDo you want to continue(y/n): ";
    char yn;    cin>>yn;
    if(yn=='y')
        goto hell;
    else 
        return 0;
}