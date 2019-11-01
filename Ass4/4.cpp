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

/*
PENDING:
        CONCATENATION OF TWO LISTS
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
    bool displayReverse(); //function is only for passing head as argument to recursive function
    void REV(node *t);
    void sortlist();
    void concatenate(list *l);
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
        cout << "\nThis is also the president and the secretary";
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
        temp->next = head;
        head = temp;
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

void list::deleteMember()
{
    if (head == NULL)
        cout << "\nNo Member is present in list";
    else
    {
        node *temp;
        if (head->next == NULL)
        {
            temp = head;
            cout << temp->name << " has been deleted and now no Member is present. " << endl;
            head = NULL;
            tail = NULL;
        }
        else
        {
            temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;
            temp->next = NULL;
            tail = temp;
            cout << temp->name << " has been deleted." << endl;
        }
    }
}

void list::deletePresident()
{
    if (head == NULL)
        cout << "\nNo President is present in list";
    else
    {
        node *temp;
        if (head->next == NULL)
        {
            temp = head;
            cout << temp->name << " has been deleted and no one is new president " << endl;
            head = NULL;
            tail = NULL;
        }
        else
        {
            temp = head;
            head = head->next;
            cout << temp->name << " has been deleted and new president is : " << head->name << endl;
        }
    }
}

void list::deleteSecretary()
{
    if (head == NULL)
        cout << "\nNo Secretary is present in list";
    else
    {
        node *temp;
        if (head->next == NULL)
        {
            temp = head;
            cout << temp->name << " has been deleted and no one is new secretary " << endl;
            head = NULL;
            tail = NULL;
        }
        else
        {
            temp = head;
            node *temp1;
            while (temp->next->next != NULL)
                temp = temp->next;
            temp1 = temp->next;
            temp->next = NULL;
            tail = temp;
            cout << temp1->name << " has been deleted " << endl;
        }
    }
}

void list::calCount()
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    cout << "\nTotal number of members are : " << count << endl;
}

void list::display()
{
    node *temp = head;
    if (head == NULL)
        cout << "\nNo members present";
    else
    {
        if (head->next == NULL)
        {
            cout << "\nPresident: ";
            cout << temp->PRN << " " << temp->name << " " << endl
                 << endl;
        }
        else
        {
            cout << "\nPresident: ";
            cout << temp->PRN << " " << temp->name << " " << endl
                 << endl;
            temp = temp->next;
            cout << "\nMembers of the Club are: \n";
            while (temp->next != NULL)
            {
                cout << temp->PRN << " " << temp->name << " " << endl;
                temp = temp->next;
            }
            cout << endl;
            cout << "\nSecretary: ";
            cout << temp->PRN << " " << temp->name << " " << endl;
        }
    }
}

bool list::displayReverse()
{
    if (head == NULL)
    {
        cout << "\nNo members present";
        return false;
    }
    node *temp = head;
    REV(temp);
    return true;
}

void list::REV(node *t)
{
    if (t == NULL)
        return; //returns the data from the "EXECUTION STACK"
    else
    {
        REV(t->next);
        cout << t->PRN << " " << t->name << endl;
    }
}

void list::sortlist()
{
    node *i, *j;
    int prn;
    string nm;

    for (i = head->next; i->next->next != NULL; i = i->next) //only members are sorted, President and Secretary are not sorted
    {
        for (j = head->next; j->next->next != NULL; j = j->next)
        {
            if ((j->PRN) > (j->next->PRN))
            {
                prn = j->PRN;
                nm = j->name;

                j->PRN = j->next->PRN;
                j->name = j->next->name;

                j->next->PRN = prn;
                j->next->name = nm;
            }
        }
    }

    cout << "\n List is sorted.";

    display();
}

void list::concatenate(list *l){
    node *temp2=head;
    node *temp1=l->head;
    if(temp1==NULL){
        cout<<"\nList 1 is empty";
        display();
        return;
    }
    if(temp2==NULL){
        cout << "\nList 2 is empty";
        cout<<"\nDirectly starts from list 1";
        l->display();
        return;
    }
    while(temp2!=NULL)
        temp2=temp2->next;
    temp2->next=temp1;
    display();
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
    cout << "\n10. SORT Members on the basis of PRN";
    if(choice==1)
        cout<<"\n";
    if (choice == 2)
    {
        cout << "\n11. CONCATENATE List 2 with 1\n";
    }
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
    case 10:
        l->sortlist();
        break;
    case 11:
        l->concatenate(&l1);
    }
    cout << "\nDo you want to continue  in the present list (y/n)";
    cin >> yn;
    if (yn == 'y' || yn == 'Y')
        goto down;
    else
        goto up;
    return 0;
}