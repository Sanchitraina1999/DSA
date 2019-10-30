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

char CONVERT::pop(){
    if(isEmpty())
        return '#';
    else
        return stack[top--];
}

void CONVERT::read(){
    cout<<"\nEnter an infix expression: ";
    cin>>infix;
}

void CONVERT::infixToPostfix(){
    int p=0,entry;
    char prev;
    for(int i=0;infix[i]!='\0';i++){
        switch(infix[i]){
            case '(':
                push(infix[i]);
                break;
            case ')':
                while((prev=pop())!='(')
                    postfix[p++]=prev;
                break;
            case '/':
            case '*':
            case '+':
            case '-':
            if(!isEmpty()){
                entry = prior(infix[i]);
                prev = pop();
                while (entry <= prior(prev))
                {
                    postfix[p++] = prev;
                    if (isEmpty())
                        break;
                    else
                        prev = pop();
                }
                if(entry>prior(prev))
                    push(prev);
            }
                
                push(infix[i]);
                break;
            default:
                postfix[p++]=infix[i];
        }
    }
    while(!isEmpty())
        postfix[p++]=pop();
    postfix[p]='\0';
    cout<<"\nThe postfix expression is: "<<postfix<<endl;
}

int CONVERT::prior(char symbol){
    switch(symbol){
        case '/':
            return 4;
        case '*':
            return 3;
        case '+':
            return 2;
        case '-':
            return 1;
        case '(':
            return 0;
        default:
            return -1;
    }
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
