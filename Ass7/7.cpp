/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[].
Write C++ program using stack to check whether given expression is well parenthesized or not.
*/
#include <iostream>
#define MAX 100
using namespace std;
class STACK
{
private:
    int top;
    char arr[MAX];

public:
    STACK()
    {
        top = -1;
    }
    bool isempty();
    bool isfull();
    void push(char);
    char pop();
    char topelement();
};

bool STACK::isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

bool STACK::isfull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

void STACK::push(char ch)
{
    arr[++top] = ch;
}

char STACK::pop()
{
    char etbd; //etbd-element to be deleted
    etbd = arr[top];
    top--;
    return etbd;
}

char STACK::topelement()
{
    return arr[top];
}
int main()
{
hell:
    STACK s;
    string expression;
    cout << "Enter the expression you want to check for paranthesized:" << endl;
    cin >> expression;
    if (expression[0] == '}' || expression[0] == ')' || expression[0] == ']')
    {
        cout << "The expression is not valid\n";
    }
    else
    {
        int i = 0;
        while (expression[i] != '\0')
        {
            switch (expression[i])
            {
            case '(':
                s.push('(');
                break;
            case '[':
                s.push('[');
                break;
            case '{':
                s.push('{');
                break;
            case '}':
                if (s.topelement() == '{')
                    s.pop();
                else
                {
                    s.push('}');
                }
                break;
            case ']':
                if (s.topelement() == '[')
                    s.pop();
                else
                {
                    s.push(']');
                }
                break;
            case ')':
                if (s.topelement() == '(')
                    s.pop();
                else
                {
                    s.push(')');
                }
                break;
            }
            i++;
        }
        if (s.isempty())
            cout << "WELL PARANTHESIZED" << endl;
        else
            cout << "NOT well paranthesized" << endl;
    }
    cout << "Do you want to continue: (y/n) " << endl;
    char yn;
    cin >> yn;
    if (yn == 'y')
        goto hell;
    else
        //do nothing
        return 0;
}