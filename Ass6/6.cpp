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
    int power;
    node *next;
};

class polynomial
{
    node *head, *tail;

public:
    polynomial()
    {
        head = NULL;
        tail = NULL;
    }
    void input();
    void output();
    void eval(int);
    void add(polynomial &);
};

void polynomial::input(){

}

void polynomial:: output(){

}

void polynomial::eval(int){

}

void polynomial::add(polynomial &){

}

int main()
{
    polynomial p1, p2, *p;
    int choice1, choice2, x;
up:
    cout << "\nPolynomial Equation using Circular Linked List";
    cout << "Equation 1";
    cout << "Equation 2";
    cout<<"\n Enter your choice : ";
    cin>>choice1;
    if(choice1==1)
        p=&p1;
    else if(choice1==2)
        p=&p2;
    else
        cout<<"\nNo such option";
down:    
    cout << "\n1. Input polynomial equation";
    cout << "\n2. Output polynomial equation";
    cout << "\n3. Evaluate the polynomial equation for a given value of x";
    cout << "\n4. Add two polynomial equation";
    cin >> choice2;
    switch (choice2)
    {
    case 1:
        p->input();
        break;
    case 2:
        p->output();
        break;
    case 3:
        cout<<"\nEnter a value of x for which you want to evaluate the polynomial ";
        cin>>x;
        p->eval(x);
    default:
        break;
    }
    return 0;
}