/*
Write C++ program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order using
a) Selection Sort b) Bubble sort
and display top five scores.
*/

#include <bits/stdc++.h>
using namespace std;

class SORT
{
private:
    int i;

public:
    void display_mainmenu(int);
    void get_marks(float[], int);
    void selection_sort(float[], int);
    void bubble_sort(float[], int);
    void display(float[], int);
    void display_top5(float[], int);
};

void SORT::display_mainmenu(int n)
{
    cout << "*****MAIN MENU*****\n";
    cout << "1. Get FE percentage of " << n << " students \n";
    cout << "2. Get percentages of " << n << " students in ascending order (by selection sort) \n";
    cout << "3. Get percentages of " << n << " students in ascending order (by bubble sort) \n";
    cout << "4. Display top 5 scores \n";
    cout << "/*Option 4 implicilty sorts the array first*/ \n";
    cout << "Enter your choice ";
}

void SORT::get_marks(float arr[], int n)
{
    cout << "Enter marks of " << n << " students: \n";
    for (i = 0; i < n; i++)
        cin >> arr[i];
}

void SORT::selection_sort(float arr[], int n){
    int i,j,min_index;
    for(i=0;i<n-1;i++){
        min_index=i;
        for(j=i+1;j<n;j++){
            if(arr[min_index]>arr[j])
                	min_index=j;
        }
        swap(arr[min_index],arr[i]);
    }
}

void SORT::bubble_sort(float arr[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void SORT::display(float arr[], int n)
{
    cout << "The scores are: \n";
    for (i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

void SORT::display_top5(float arr[], int n)
{
    sort(arr, arr + n);
    cout << "The top 5 scores are: \n";
    for (i = n - 1; i >= n - 5; i--)
        cout << arr[i] << "  ";
    cout << endl;
}

int main()
{
    int choice, n;
    char ch;
    SORT s;
    cout << "Enter the number of students: \n";
    cin >> n;
    float arr[n];
label:

    s.display_mainmenu(n);
    cin >> choice;
    switch (choice)
    {
    case 1:
        s.get_marks(arr, n);
        s.display(arr, n);
        break;
    case 2:
        s.selection_sort(arr, n);
        s.display(arr, n);
        break;
    case 3:
        s.bubble_sort(arr, n);
        s.display(arr, n);
        break;
    case 4:
        s.display_top5(arr, n);
        break;
    default:
        cout << "You have entered a wrong choice \n";
    }

    cout << "Do you want to continue (y/n) \n";
    cin >> ch;
    if ((ch == 'y') || (ch == 'Y'))
        goto label;
    else
        cout << "You have chose to exit !! \n";
    return 0;
}
