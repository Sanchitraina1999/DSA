/*
Write a C++ program to realize polynomial equation using circular link list and perform following operation
. To input & output polynomials 
. Evaluates a polynomial at given value of x 
. Add two polynomials. 
*/

/*
    ADD TWO POLYNOMIALS
*/
#include <iostream>
#include<math.h>
using namespace std;

class node
{
public:
    int value;
    node *next;
};

class polynomial
{
    node *head, *tail;

public:
    int degree;
    polynomial()
    {
        head = NULL;
        tail = NULL;
        degree = 0;
    }
    void input(int);
    void output();
    void eval(int);
    void add(polynomial &);
};

void polynomial::input(int n)
{
    int val;
    for (int i = 0; i <= n; i++)
    {
        cout << "Enter the value of the coefficient of the " << (n - i) << " power : ";
        cin >> val;
        node *temp = new node();
        temp->value = val;
        temp->next = NULL;
        if (head == NULL)
        {
            head = tail = temp;
            tail->next = head;
            cout << head->value << " inserted at beginning\n";
        }
        else
        {
            tail->next = temp;
            tail = temp;
            tail->next = head;
            cout << tail->value << " inserted at end\n";
        }
    }
}

void polynomial::output()
{
    node *temp=head;
    if(temp==NULL)
        cout<<"\nNo polynomial inputed (present) ";
    else{
        int d=degree;
        while(temp->next!=head){
            cout<<temp->value<<"x^"<<d;
            d--;
            cout<<" + ";
            temp=temp->next;
        }
        cout<<temp->value<<"\n";
    }
}

void polynomial::eval(int x)
{
    int sum=0;
    node *temp=head;
    if (temp == NULL)
        cout << "\nNo polynomial present";
    else
    {
        int d = degree;
        while (temp->next != head)
        {
            sum += ((temp->value)*pow(x,d));
            d--;
            temp = temp->next;
        }
        sum +=(temp->value);
        cout << "\nThe value of \n";
        output();
        cout<<"at x = "<<x<<" is : "<<sum<<endl;
    }
}

void polynomial::add(polynomial &p1)
{
    node *temp2=head;
    node *temp1=p1.head;

    if(degree==0){
        cout << "\nPolynomial 2 is not inputed\n";
        p1.output();
    }
    else if(p1.degree==0)
    {
        cout << "\nPolynomial 1 is not inputed\n";
        output();
    }
    else{
        if(degree>p1.degree){
            while (degree > p1.degree)
            {
                temp2 = temp2->next;
            }
        }

        if (degree < p1.degree)
        {
            while (degree < p1.degree)
            {
                temp1 = temp1->next;
            }
        }

        while(temp1->next != p1.head || temp2 -> next != head ){
            temp2->value = temp2->value + temp1 -> value;
            temp1=temp1->next;
            temp2=temp2->next;
        }

        output();
    }
}

int main()
{
    polynomial p1, p2, *p, psum;
    int choice1, choice2, x;
    char yn;
up:
    cout << "\nPolynomial Equation using Circular Linked List";
    cout << "\nEquation 1";
    cout << "\nEquation 2";
    cout << "\nEnter your choice : ";
    cin >> choice1;
    if (choice1 == 1)
        p = &p1;
    else if (choice1 == 2)
        p = &p2;
    else
        cout << "\nNo such option";
down:
    cout << "\n1. Input polynomial equation";
    cout << "\n2. Output polynomial equation";
    cout << "\n3. Evaluate the polynomial equation for a given value of x";
    if (choice1 == 1)
        cout << endl;
    if (choice1 == 2)
        cout << "\n4. Add two polynomial equation\n";
    cin >> choice2;
    switch (choice2)
    {
    case 1:
        cout << "Enter the degree of the polynomial";
        cin >> p->degree;
        p->input(p->degree);
        break;
    case 2:
        if (p->degree == 0)
            cout << "\nEquation is not inputed";
        else
            p->output();
        break;
    case 3:
        cout << "\nEnter a value of x for which you want to evaluate the polynomial ";
        cin >> x;
        p->eval(x);
        break;
    case 4:
        psum=p2;
        psum.add(p1);
        break;
    default:
        cout << "\nNo such option";
        break;
    }
    cout << "\nDo you want to continue (y/n) : ";
    cin >> yn;
    if (yn == 'y')
        goto down;
    else
        goto up;
    return 0;
}