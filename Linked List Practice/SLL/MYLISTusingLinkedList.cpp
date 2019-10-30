/*
    MYLIST using Linked List
*/
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

class MYLIST
{
private:
    node *head, *tail;

public:
    MYLIST()
    {
        head = tail = NULL;
    }
    void push_front(int);
    void push_back(int);
    void push_after(int, int);
    void pop_front();
    void pop_back();
    void pop_after(int);
    void show();
};

void MYLIST::push_front(int item)
{
    node *temp = new node();
    temp->data = item;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;

        cout << head->data << " inserted to the front of the MyList , that was just created\n";
    }
    else
    {
        temp->next = head;
        head = temp;
        cout << head->data << " inserted to the front of the MyList\n";
    }
    show();
}

void MYLIST::push_back(int item)
{
    node *temp = new node();
    temp->data = item;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        cout << head->data << " inserted to the back of the MyList , that was just created\n";
    }
    else
    {
        node *temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->next = NULL;
    }
    show();
}

void MYLIST::push_after(int val, int item)
{
    node *temp = new node();
    temp->data = item;
    node *temp1 = head;
    node *temp2 = head->next;
    int found = 0;
    if(head==NULL)
        cout<<"\nMyList is empty";
    else{
        while (temp1 != NULL && found == 0)
        {
            if (temp1 -> data == val)
            {
                found = 1;
            }
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        if (found == 1)
        {
            temp1->next = temp;
            temp->next = temp2;
        }
        else if(found == 0)
        {
            cout<<"\nMyList has no element : "<<val<<"\n";
        }
    }
    show();
}

void MYLIST::pop_front()
{
    if (head == NULL)
        cout << "\nMyList is empty";
    else
    {
        head = head->next;
    }
    show();
}

void MYLIST::pop_back()
{
    if (head == NULL)
        cout << "\nMyList is empty";
    else
    {
        node *temp = head;
        if (temp->next == NULL)
        {
            cout << temp->data << " was deleted and now MyList is empty";
            head = NULL;
            tail = NULL;
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }
    show();
}

void MYLIST::pop_after(int val)
{
    if(head==NULL)
        cout << "\nMyList is empty";
    else{
        node *temp = head;
        if(head -> data == val){
            cout<<"\nFound at start of MyList";
            head=head->next;
            cout<<" Now, new start of MyList is: "<<head->data<<"\n";
        }
        else{
            node *temp1 = head->next;
            while (temp1 != NULL)
            {
                if (temp1 -> data == val)
                {
                    break;
                }
                temp = temp->next;
                temp1 = temp1->next;
            }
            if(temp1!=NULL){
                temp->next=temp1->next;
            }
            else{
                cout<<val<<" not found in MyList\n";
            }
        }
    }
    show();
}

void MYLIST::show()
{
    node *temp = head;
    if (head == NULL)
        cout << "\nMyList is empty";
    else
    {
        cout << "\nMyList is :\n";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}
int main()
{
    MYLIST ml;
    int choice, n, val;
    char yn;
up:
    cout << "\nMYLIST USING LINKED LIST\n";
    cout << "1. PUSH onto MYLIST's front\n";
    cout << "2. PUSH onto MYLIST's back\n";
    cout << "3. PUSH after a MYLIST's value\n";
    cout << "4. POP from the MYLIST's front\n";
    cout << "5. POP from the MYLIST's back\n";
    cout << "6. POP after a value in MYLIST\n";
    cout << "7. DISPLAY the MYLIST\n";
    cout << "Enter your choice\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nEnter number to be pushed into the MYLIST at the front";
        cin >> n;
        ml.push_front(n);
        break;
    case 2:
        cout << "\nEnter number to be pushed into the MYLIST at the back";
        cin >> n;
        ml.push_back(n);
        break;
    case 3:
        cout << "\nEnter position and number to be pushed into the MYLIST after position\n";
        cin >> val >> n;
        ml.push_after(val, n);
        break;
    case 4:
        ml.pop_front();
        break;
    case 5:
        ml.pop_back();
        break;
    case 6:
        cout << "\nEnter position and number to be pushed into the MYLIST after position\n";
        cin >> val;
        ml.pop_after(val);
        break;
    case 7:
        ml.show();
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