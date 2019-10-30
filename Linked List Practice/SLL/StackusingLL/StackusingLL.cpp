/*
    STACK using Linked List
*/
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

class STACK
{
    node *head, *tail;

public:
    STACK()
    {
        head = tail = NULL;
    }
    void push(int);
    void pop();
    void show();
};

void STACK::push(int item)
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
        tail->next = temp;
        tail = tail->next;
    }
}

void STACK::pop()
{
    if (head == NULL)
        cout << "\nSTACK is empty";
    else
    {
        node *temp = head;
        if (head->next == NULL)
        {
            cout << head->data << " deleted from the beginning of the list";
            head = NULL;
        }
        else
        {
            while (temp -> next -> next != NULL){
                temp = temp -> next;
            }
            cout<< temp -> next -> data<<" was deleted from the end of the list";
            temp -> next = NULL;
        }
    }
    show();
}

void STACK::show()
{
    node *temp = head;
    if (head == NULL)
        cout << "\nSTACK is empty";
    else
    {
        cout << "\nSTACK is : \n";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int main()
{
    STACK s;
    int choice, n;
    char yn;
up:
    cout << "STACK USING LINKED LIST\n";
    cout << "1. PUSH onto STACK\n";
    cout << "2. POP from the STACK\n";
    cout << "3. DISPLAY the STACK\n";
    cout << "Enter your choice\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nEnter number to be pushed into the stack";
        cin >> n;
        s.push(n);
        break;
    case 2:
        s.pop();
        break;
    case 3:
        s.show();
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
