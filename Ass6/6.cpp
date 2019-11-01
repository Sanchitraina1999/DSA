/*
Write a C++ program to realize polynomial equation using circular link list and perform following operation
. To input & output polynomials 
. Evaluates a polynomial at given value of x 
. Add two polynomials. 
*/
#include <iostream>
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
    node *temp = new node();
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of the coefficient of the " << (n - i) << " power : ";
        cin >> val;
        
        temp->value = val;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
            tail->next = head;
        }
        else
        {
            tail->next = temp;
            temp = tail;
            tail->next = head;
        }
    }
}

void polynomial::output()
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "Equation - NULL";
    }
    else
    {
        int i = degree;
        while (temp != head)
        {
            cout << temp->value << "x^" << degree;
            if (degree != 0)
                cout << "+";
            degree--;
            temp = temp->next;
        }
    }
}

void polynomial::eval(int)
{
}

void polynomial::add(polynomial &)
{
}

int main()
{
    polynomial p1, p2, *p;
    int choice1, choice2, x;
    char yn = 'y';
up:
    cout << "\nPolynomial Equation using Circular Linked List";
    cout << "\nEquation 1";
    cout << "\nEquation 2";
    cout << "\n Enter your choice : ";
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
        p2.add(p1);
        break;
    case 5:
        yn = 'n';
        break;
    default:
        cout << "\nNo such option";
        break;
    }
    cout<<"\nDo you want to continue (y/n) : ";
    cin>>yn;
    if(yn=='y')
        goto down;
    else
        goto up;    
    return 0;
}