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
    int n, val;
    cout<<"Enter the degree of the polynomial";
    cin>>n;
    for(int i=0;i<n;i++){
        node *temp = new node();

        cout << "Enter the value of the coefficient of the "<< (n-i+1) <<" power : ";
        cin>>val;
        temp->value = val;

        if(head==NULL){
            head=temp;
            tail=temp;
            tail->next=head;
        }
        else{
            tail->next=temp;
            temp=tail;
            tail->next=head;
        }
    }
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
    if (choice1 == 1)
        cout<<endl;
    if (choice1 == 2)
            cout << "\n4. Add two polynomial equation\n";
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
        break;
    case 4:
        p2.add(p1);
        break;
    default:
        cout << "\nNo such option";
        break;
    }
    return 0;
}