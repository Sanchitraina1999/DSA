/*
    QUEUE using Linked List
*/
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

class QUEUE
{
    node *head, *tail;

public:
    QUEUE()
    {
        head = tail = NULL;
    }
    void push(int);
    void pop();
    void show();
};

void QUEUE::push(int item)
{
    node *temp = new node();
    temp->data = item;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail -> next = temp;
        tail = tail->next;
    }
}

void QUEUE::pop()
{
    if (head == NULL)
        cout << "\nQUEUE is empty";
    else
    {
        node *temp = head;
        if (head == tail)
        {
           cout<<"\n"<<head -> data <<" deleted from the queue and now queue is empty";
           head = NULL;
           tail = NULL;
        }
        else
        {
            cout << "\n"<< head->data << " deleted from the queue";
            head = head -> next;
            cout<<" and new front becomes : "<<head -> data;
        }
    }
    show();
}

void QUEUE::show()
{
    node *temp = head;
    if (head == NULL)
        cout << "\nQUEUE is empty";
    else
    {
        cout << "\nQUEUE is : \n";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int main()
{
    QUEUE q;
    int choice, n;
    char yn;
up:
    cout << "\nQUEUE USING LINKED LIST\n";
    cout << "1. PUSH onto QUEUE\n";
    cout << "2. POP from the QUEUE\n";
    cout << "3. DISPLAY the QUEUE\n";
    cout << "Enter your choice\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nEnter number to be pushed into the queue";
        cin >> n;
        q.push(n);
        break;
    case 2:
        q.pop();
        break;
    case 3:
        q.show();
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
