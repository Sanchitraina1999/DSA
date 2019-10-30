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
int top;
char infix[MAX], postfix[MAX], stack[MAX];
public:
    CONVERT(){
        top=-1;
    }
    bool isEmpty();
    bool isFull();
    void push(char);
    char pop();
    void read();
    void infixToPostfix();
    int prior(char);
};

bool CONVERT::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;    
}

bool CONVERT::isFull(){
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

void CONVERT::push(char symbol){
    if(isFull())
        cout<<"\nOverflow";
    else
        stack[++top]=symbol;
}

int main(){
    char choice;
    CONVERT c;
up:
    c.read();
    c.infixToPostfix();
    cout<<"\nDo you want to continue? (y/n) : ";
    cin>>choice;
    if(choice=='y')
        goto up;
    else
        return 0;
}
