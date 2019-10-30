/*
 Implement C++ program for expression conversion as infix to postfix and its evaluation
 using stack based on given conditions:  Operands and operator, both must be single
 character, Input Postfix expression must be in a desired format, Only '+', '-', '*'
 and '/ ' operators are expected.
*/
#include<iostream>
#define MAX 100
using namespace std;
class CONVERT{
char infix[MAX], postfix[MAX], stack[MAX];
public:
    void push(char);
    bool isEmpty();
    bool isFull();
    
}
