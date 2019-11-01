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

class list
{
    node *head, *tail;

public:
    list()
    {
        head = NULL;
        tail = NULL;
    }
};

int main()
{
    cout << "\nPolynomial Equation using Circular Linked List";
    cout << "\n1. Input polynomial equation";
    cout << "\n2. Output polynomial equation";
    cout << "\n3. Equalate the polynomial equation for a given value of x";

    return 0;
}