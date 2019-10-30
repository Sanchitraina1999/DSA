/*
    DEQUEUE using Circular Linked List
*/
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next, *prev;
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
    void reverseshow();
};

void DEQUEUE::push_front(int item)
{
    node *temp = new node();
    temp->data = item;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        cout<<head->data<<" inserted to the front of the deque , that was just created\n";
        tail -> next = NULL;
        head -> prev = NULL;
    }
    else
    {
        temp -> next = head;
        head -> prev = temp;
        head = temp;
        cout<<head->data<<" inserted to the front of the deque\n";
        head -> prev = NULL;
    }
    show();
}

void DEQUEUE::push_back(int item)
{
    node *temp = new node();
    temp->data = item;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        cout << head->data << " inserted to the back of the deque , that was just created\n";
        head -> prev = NULL;
        tail -> next = NULL;
    }
    else
    {
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
        tail -> next = NULL;
    }
    show();
}

void DEQUEUE::pop_front()
{
    if (head == NULL)
        cout << "\nDequeue is empty";
    else{
        head = head -> next;
        head -> prev = NULL;
    }
    show();
}

void DEQUEUE::pop_back()
{
    if (head == NULL)
        cout << "\nDequeue is empty";
    else{
        tail = tail -> prev;
        tail -> next = NULL;
    }
    show();
}

void DEQUEUE::show()
{
    node *temp = head;
    if(head==NULL)
        cout<<"\nDequeue is empty";
    else{
        cout<<"\nDequeue is :\n";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}

void DEQUEUE::reverseshow(){
    node *temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp -> prev;
    }
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
    cout << "6. REVERSE DISPLAY the DEQUEUE\n";
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
        break;
    case 5:
        dq.show();
        break;
    case 6:
        dq.reverseshow();
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