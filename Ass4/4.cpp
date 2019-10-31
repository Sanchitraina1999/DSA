/*
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department 
can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club 
and last node is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. 
Store student PRN and Name. Write functions to 
. Add and delete the members as well as president or even secretary. 
. Compute total number of members of club
. Display members
. Display list in reverse order using recursion
. Two linked lists exists for two divisions. Concatenate two lists
. Sort the singly linked list.
*/
#include <iostream>
using namespace std;

class node
{
public:
    int PRN;
    string name;
    node *next;
};

class list
{
    node *head, *tail;

public:
    list()
    {
        head = NULL;
        tail = NULL;
    }
    void addMember(int, string);
    void addPresident(int, string);
    void addSecretary(int, string);
    void deleteMember();
    void deletePresident();
    void deleteSecretary();
    void calCount();
    void display();
    void displayReverse();
};

void list::addMember(int prn, string nm)
{
    node *temp = new node();
    temp->PRN = prn;
    temp->name = nm;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        cout << "This is also the president";
        tail->next = NULL;
    }
    else
    {
        node *temp1 = head;
        if (temp1->next == NULL)
        {
            temp1->next = temp;
            temp->next = NULL;
            tail = temp;
            cout << "This is also the secretary";
        }
        else
        {
            while (temp1->next->next != NULL)
                temp1 = temp1->next;
            node *temp2 = temp1->next;
            temp1->next = temp;
            temp->next = temp2;
            temp2->next = NULL;
            tail = temp2;
        }
    }
}

void list::addPresident(int prn, string nm)
{
    node *temp = new node();
    temp->PRN = prn;
    temp->name = nm;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        tail->next = NULL;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void list::addSecretary(int prn, string nm)
{
    node *temp = new node();
    temp->PRN = prn;
    temp->name = nm;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        tail->next = NULL;
    }
    else
    {
        node *temp1 = head;
        if (temp1->next == NULL)
        {
            temp1->next = temp;
            temp->next = NULL;
            tail = temp;
        }
        else
        {
            while (temp1->next != NULL)
                temp1 = temp1->next;
            temp1->next = temp;
            temp->next = NULL;
            tail = temp;
        }
    }
}

void list::deleteMember(){

}

void list::deletePresident(){
    if(head==NULL)
        cout<<"\nNo President is present in list";
    else{
        node *temp;
        if(head->next==NULL){
            
        }
        else{
            temp = head;
            head = head->next;
            cout << temp->name << " has been deleted and new president is : " << head->name << endl;
        }
    }
}

void list::deleteSecretary(){
    
}

void list::calCount(){
    int count=0;
    node *temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    cout<<"\nTotal number of members are : "<<count<<endl;
}

void list::display(){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->PRN<<" "<<temp->name<<" "<<endl;
        temp=temp->next;
    }
}

void list::displayReverse(){

}

int main()
{
    list *l;
    int choice, choice1;
    list l1, l2;
    int prn;
    string nm;
    char yn;
up:
    cout << "\n Enter your choice for list: ";
    cout << "\n1. List 1";
    cout << "\n2. List 2";
    cin >> choice;
down:
    if (choice == 1)
    {
        l = &l1;
        cout << "\nOperations on List 1: ";
    }
    else if (choice == 2)
    {
        l = &l2;
        cout << "\nOperations on List 2: ";
    }
    cout << "\n1. Add Member";
    cout << "\n2. Add President";
    cout << "\n3. Add Secretary";
    cout << "\n4. Delete Member";
    cout << "\n5. Delete President";
    cout << "\n6. Delete Secretary";
    cout << "\n7. Calculate Number of Members";
    cout << "\n8. Display All Members";
    cout << "\n9. Display All Members in reverse order";
    cin >> choice1;
    switch (choice1)
    {
    case 1:
        cout << "\nEnter PRN and Name of the member";
        cin >> prn >> nm;
        l->addMember(prn, nm);
        break;
    case 2:
        cout << "\nEnter PRN and Name of the president";
        cin >> prn >> nm;
        l->addPresident(prn, nm);
        break;
    case 3:
        cout << "\nEnter PRN and Name of the Secretary";
        cin >> prn >> nm;
        l->addSecretary(prn, nm);
        break;
    case 4:
        l->deleteMember();
        break;
    case 5:
        l->deletePresident();
        break;
    case 6:
        l->deleteSecretary();
        break;
    case 7:
        l->calCount();
        break;
    case 8:
        l->display();
        break;
    case 9:
        l->displayReverse();
        break;
    }
    cout<<"\nDo you want to continue  in the present list (y/n)";
    cin>>yn;
    if(yn=='y' || yn=='Y')
        goto up;
    else
        goto down;
    return 0;
}