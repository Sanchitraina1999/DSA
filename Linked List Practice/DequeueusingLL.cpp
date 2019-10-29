/*
    DEQUEUE using Linked List
*/
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

class DEQUEUE
{
private:
    node *head, *tail;

public:
    DEQUEUE()
    {
        head = tail = NULL;
    }
    void push_front(int);
    void push_back(int);
    void pop_front();
    void pop_back();
    void show();
};

void DEQUEUE::push_front(int item)
{
    node *temp = new node();
    temp->data = item;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
}

void DEQUEUE::push_back(int item)
{
}

void DEQUEUE::pop_front()
{
}

void DEQUEUE::pop_back()
{
}

void DEQUEUE::show()
{
}
int main()
{
    DEQUEUE dq;
    int choice, n;
    char yn;
up:
    cout << "\nDEQUEUE USING LINKED LIST\n";
    cout << "1. PUSH onto DEQUEUE's front\n";
    cout << "2. PUSH onto DEQUEUE's back\n";
    cout << "3. POP from the DEQUEUE's front\n";
    cout << "4. POP from the DEQUEUE's back\n";
    cout << "5. DISPLAY the DEQUEUE\n";
    cout << "Enter your choice\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nEnter number to be pushed into the dequeue at the front";
        cin >> n;
        dq.push_front(n);
        break;
    case 2:
        cout << "\nEnter number to be pushed into the dequeue at the back";
        cin >> n;
        dq.push_back(n);
        break;
    case 3:
        dq.pop_front();
        break;
    case 4:
        dq.pop_back();
    case 5:
        dq.show();
        break;
    default:
        cout << "\nYou have entered a wrong choice";
    }
    cout << "\nDo you want to continue? (y/n) ";
    cin >> yn;
    if (yn == 'y')
        goto up;
    else
        return 0;
}