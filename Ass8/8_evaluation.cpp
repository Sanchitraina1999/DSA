/* Implement C++ program for expression evaluation using stack based on given conditions: 
 Operands and operator, both must be single
 character, Input Postfix expression must be in a desired format, Only '+', '-', '*'
 and '/ ' operators are expected.
*/
#include<iostream>
#define MAX 100
using namespace std;
class STACK{
    int top;
    char arr[MAX];
    char exp[MAX];
public:
    STACK(){
        top=-1;
    }
    void get_STACK();
    int result();
    void push(double);
    int pop();
    bool empty();
    bool full();
};

void STACK::get_STACK(){
    cout<<"Enter an expression : (only numbers 0-9 are accepted) ";
    cin>>exp;
    cout<<exp<<endl;
}

int STACK::result(){
    int i=0,op2,op1;
    double num;
    while(exp[i]!='\0'){
        if(exp[i] >= '0' && exp[i] <= '9'){
            num = int(exp[i]) - 48;
            push(num);
        }
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
            op1 = pop();
            op2 = pop();
            switch(exp[i]){
                case '+':
                    push(double(op2 + op1));
                    break;
                case '*':
                    push(double(op2 * op1));
                    break;
                case '/':
                    push(double(op2 / op1));
                    break;
                case '-':
                    push(double(op2 - op1));
                    break;
            }
        }
        i++;
    }
    cout<<"\nResult is : "<<pop();
}

void STACK::push(double n)
{
    if(!full())
        arr[++top]=n;
}

int STACK::pop(){
    if(!empty())
        return arr[top--];
}

bool STACK::empty(){
    if(top==-1)
        return 1;
    else
        return 0;    
}

bool STACK::full(){
    if(top==MAX-1)
        return 1;
    else
        return 0;    
}

int main(){
    STACK s;
    char yn;
up:
    s.get_STACK();
    s.result();
    cout<<"\nDo you want to continue : (y/n) ";
    cin>>yn;
    if(yn=='y' || yn=='Y')
        goto up;
    else
        return 0;
}
