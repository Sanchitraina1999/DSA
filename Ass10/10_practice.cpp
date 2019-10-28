/*
A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end.
Obtain a data representation mapping a deque into a one-dimensional array. Write C++ program to simulate deque
with functions to add and delete elements from either end of the deque.
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class DEQUEUE
{
    int front, rear, arr[MAX];

public:
    DEQUEUE()
    {
        front = rear = -1;
    }
    void enqueue_f(int);
    void enqueue_r(int);
    void delqueue_f();
    void delqueue_r();
    void display();
    bool isFull();
    bool isEmpty();
};
void DEQUEUE::enqueue_r(int x)
{
    if(isFull())
        cout<<"\nDeque is full";
    else if(rear==MAX-1)
        rear=0;
    else if(front==-1){
        front=rear=0;
    }
    else{
        rear++;
    }
    arr[rear]=x;    
}

void DEQUEUE::enqueue_f(int x)
{
    
}

void DEQUEUE::delqueue_f()
{
   
}

void DEQUEUE::delqueue_r()
{
    
}

void DEQUEUE::display()
{

}
bool DEQUEUE::isEmpty()
{
    if(front==-1)
        return 1;
    else
        return 0;    
}

bool DEQUEUE::isFull()
{
    if( (front==0 && rear==MAX-1) || (front==rear+1) )
        return 1;
    else
        return 0;    
}

int main()
{
    DEQUEUE obj;
    int choice, choice1, n;
    char opt;
hell:
    cout << "Main Menu:\n";
    cout << "1. INSERT element\n";
    cout << "2. DELETE element\n";
    cout << "3. DISPLAY DEQUEUE\n";
    cout << "4. EXIT\n";
    cout << "Enter your choice:\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "INSERT menu\n";
        cout << "1.1 INSERT at FRONT\n";
        cout << "1.2 INSERT at REAR\n";
        cout << "1.3 exit to main menu\n";
        cout << "Enter your choice\n";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
        {
            cout << "Enter data to be inserted into the dequeue at front\n";
            cin >> n;
            obj.enqueue_f(n);
            break;
        }
        case 2:
        {
            cout << "Enter data to be inserted into the dequeue at rear\n";
            cin >> n;
            obj.enqueue_r(n);
            break;
        }
        case 3:
        {
            cout << "Going to main menu\n";
            goto hell;
            break;
        }
        default:
        {
            cout << "Invalid choice entered\n";
            cout << "Going to main menu\n";
            goto hell;
        }
        }
        break;
    }
    case 2:
    {
        cout << "DELETE menu\n";
        cout << "2.1 DELETE from FRONT\n";
        cout << "2.2 DELETE from REAR\n";
        cout << "2.3 exit to main menu\n";
        cout << "Enter your choice\n";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
        {
            obj.delqueue_f();
            break;
        }
        case 2:
        {
            obj.delqueue_r();
            break;
        }
        case 3:
        {
            cout << "Going to main menu\n";
            goto hell;
            break;
        }
        default:
        {
            cout << "Invalid choice entered\n";
            cout << "Going to main menu\n";
            goto hell;
        }
        }
        break;
    }
    case 3:
    {
        obj.display();
        break;
    }
    case 4:
    {
        cout << "Exiting program\n";
        exit(1);
        break;
    }
    default:
    {
        cout << "Invalid choice entered\n";
    }
    }
    cout << "\nDo you want to continue using the program:(y/n)";
    cin >> opt;
    if ((opt == 'y') || (opt == 'Y'))
        goto hell;
    else
        //do nothing

        return 0;
}