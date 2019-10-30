/*
 Implement C++ program for expression conversion as infix to postfix and its evaluation
 using stack based on given conditions:  Operands and operator, both must be single
 character, Input Postfix expression must be in a desired format, Only '+', '-', '*'
 and '/ ' operators are expected.
 */
#include<iostream>
#define MAX 100
using namespace std;
class STACK{
    int top;
    char infix[MAX], postfix[MAX], stackArray[MAX];
public:
    STACK(){
        top=-1;
    }
    void read();
    bool isEmpty();
    bool isFull();
    void push(char);
    void infixToPostfix();
    char pop();
    int prior(char);
};

void STACK::read(){
    cout<<"\nEnter an infix expression: ";
    cin>>infix;
}

bool STACK::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

bool STACK::isFull(){
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

void STACK::push(char symbol){
    if(!isFull())
        cin>>stackArray[top++];
    else
        cout<<"\nOverflow";  
}

char STACK::pop(){
    if(!isEmpty())
        return stackArray[top--];
    else
        cout<<"\nUnderflow";    
}

void STACK::infixToPostfix(){
    char prev;
    int p=0, entry;
    for(int i=0;infix[i]!='\0';i++){
        switch(infix[i]){
            case '(':
                push(infix[i]);
                break;
            case ')':
                while((prev==pop())!='(')
                    postfix[p++]=prev;
                break;
            case '/':
            case '*':
            case '+':
            case '-':
                if (!isEmpty())
                {   
                    entry=prior(infix[i]);
                    prev=pop();
                    while(entry<=prior(prev)){
                        postfix[p++]=prev;
                        if(!isEmpty())
                            prev=pop();
                        else
                            break;
                    }
                    if(entry>prior(prev))
                        push(prev);
                }
                push(infix[i]);
                break;
            default:
                postfix[p++] = entry;
        }

    }
    while(!isEmpty())
        postfix[p++] = pop();
    postfix[p]='\0';
    cout << "\nThe postfix expression is: " << postfix << endl;
}

int STACK::prior(char symbol){
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
    STACK s;
    char choice;
up: 
    s.read();
    s.infixToPostfix();
    cout<<"\nDo you want to continue? (y/n) : ";
    cin>>choice;
    if(choice=='y' || choice=='Y')
        goto up;
    else
        return 0;
}