/*
        LINKED LIST
*/

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
};

class Linkedlist
{
private:
    node *head, *tail;
public:
    Linkedlist(){
        head=tail=NULL;
    }
    void add(int);
    void Delete(int);
    void display();   
};

void Linkedlist::add(int item){
    node *temp =new node();
    temp -> data = item;
    temp -> next = NULL;

    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail -> next = temp;
        tail = tail -> next;
    }
}

void Linkedlist::Delete(int item){
    node *temp = head;
    if(head==NULL){
        cout<<"\nLinked List is empty";
    }
    if(head->data == item){ //deletion from front
        cout<<"\n";
        cout<<head->data<<" was deleted from the beginning of the linked list";
        head = head -> next;
    }
    else{
        while(temp -> next -> next != NULL){
            if(temp->data == item){
                cout << temp -> data << " was deleted from the linked list";
                break;
            }
            else
                temp = temp -> next;
        }
        
    }
    /*
    else{
        while(temp -> next != NULL){
            if(temp -> next -> data == item){
                cout << "\n";
                cout << temp -> next ->data << " was deleted from the linked list";
                temp -> next = temp -> next -> next;
                break;
            }
        }
    }
    */
}

void Linkedlist::display(){
    node *temp=head;
    if(head==NULL){
        cout<<"\n Linked List is empty";
    }
    else{
        while(temp != NULL){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
    }
}

int main(){
    Linkedlist ll;
    cout<<"Number of numbers: ";
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ll.add(arr[i]);
    }
    cout<<"\nLinked List is: ";
    ll.display();
    up:
    cout<<"\nEnter number of numbers you want to delete";
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
        ll.Delete(arr1[i]);
        cout << "\nLinked List is: ";
        ll.display();
    }
    goto up;
    return 0;
}