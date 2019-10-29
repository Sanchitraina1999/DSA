/*
    STACK using Linked List
*/
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
};

class STACK{
    node *head, *tail;
public:
    STACK(){
        head=tail=temp;
    }
    void push(int);
    void pop();
    void show();
}

int main(){
    STACK s;
    int choice,n;
    char yn;
    cout<<"STACK USING LINKED LIST\n";
    cout<<"1. PUSH onto STACK\n";
    cout<<"2. POP from the STACK\n";
    cout<<"3. DISPLAY the STACK\n";
    out<<"Enter your choice\n";
    cin>>choice;
    switch(choice){
        case 1:
                cout<<"\nEnter number to be pushed into the stack";
                cin>>n;
                s.push(n);
                break;
        case 2:
                s.pop();
                break;
        case 3:
                s.show();
                break;
        default:
                cout<<"\nYou have entered a wrong choice";
    }   
    cout<<"\nDo you want to continue? (y/n) ";
    cin>>yn;
    if(yn=='y')
        goto up;
    else
        return 0;
}
