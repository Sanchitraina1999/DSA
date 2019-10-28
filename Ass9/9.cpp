/*
Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system.
If the operating system does not use priorities, then the jobs are processed in the order they enter the system.
Write C++ program for simulating job queue. Write functions to add job and delete job from queue. 
*/
#include <iostream>
#define MAX 100
using namespace std;
class QUEUE
{
private:
    int front, rear, arr[MAX];

public:
    QUEUE()
    {
        front = rear = -1;
    }
    void push(int);
    void pop();
    void show();
};

void QUEUE::push(int item)
{
    if((front==0 && rear==MAX-1) || (front==rear+1) ){
        cout<<"\nQueue is full";
    }
    else if(){

    }
}

void QUEUE::pop()
{
    
}

void QUEUE::show(){zz
       
}
int main()
{
    QUEUE Q;
    int choice, item;
hell:
    cout << "\nQUEUE\n";
    cout << "1. PUSH \n";
    cout << "2. POP\n";
    cout << "3. DISPLAY QUEUE\n";
    cout << "Enter your choice\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter element to be pushed into the queue: \n";
        cin >> item;
        Q.push(item);
        break;
    case 2:
        Q.pop();
        break;
    case 3:
        Q.show();
        break;
    default:
        cout << "Wrong choice entered \n";
    }
    cout << "\nDo you want to continue? (y/n) \n";
    char y;
    cin >> y;
    if (y == 'y')
        goto hell;
    else
        return 0;
}