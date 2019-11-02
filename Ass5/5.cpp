/*
The ticket booking system of Cinemax theater has to be implemented using C++ program.
There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained to keep track of free seats at rows. 
Assume some random booking to start with. Use array to store pointers (Head pointer) to each row. 
On demand 
. The list of available seats is to be displayed 
. The seats are to be booked 
. The booking can be cancelled.
*/
#include<iostream>
using namespace std;

class node{
    int booking;
    node *next, *prev;
};

class TICKET{
    node *head,*tail;
public:
    TICKET()
    {
        head=tail=NULL;
    }
    void available();
    void book();
    void cancel();
};



int main(){
    TICKET t;
    int choice;
    char yn;
up:
    cout<<"\nTicket Booking System of Cinemax Theater";
    cout<<"\n1. The list of available seats";
    cout<<"\n2. Book seats";
    cout<<"\n3. Cancel seat booking";
    cin>>choice;
    switch(choice){
        case 1:
            t.available();
            break;
        case 2:
            t.book();
            break;
        case 3: 
            t.cancel();
            break;
        default:
            cout<<"\nNo such choice";
   }
   cout<<"\nDo you want to continue (y/n) : ";
   cin>>yn;
   if(yn=='y')
        goto up;
   else
        return 0;
}