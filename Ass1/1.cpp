/*
Write C/C++ program to store marks scored for first test of subject 'Data Structures and
Algorithms' for N students. Compute
I. The average score of class
II. Highest score and lowest score of class
III. Marks scored by most of the students
IV. list of students who were absent for the test
*/
#include<iostream>
#define MAX 100
using namespace std;
int i;
class TEST{
    int n;      // number of students
    int attendance[MAX];
    string name[MAX];
    int roll_no[MAX];
    int marks[MAX];
public:
    void get_details();
    void average();
    void highlow();
    void mostfreq();
    void absent();
};

void TEST::get_details(){
    cout<<"Enter the number of students in the class : ";
    cin>>n;
    cout<<"\nEnter the details of these "<<n<<" students in class : \n";
    for(i=0;i<n;i++){
        cout << "\nEnter the name, roll number, attendance(0 for absent and 1 for present) and marks of " << i+1 << " student: ";
        cin>>name[i];
        cin>>roll_no[i];
        cin>>attendance[i];
        if(attendance[i]!=0)
            cin>>marks[i];
        else{
            cout<<"As, this student is absent , marks for this student is automatically considered as 0"; 
            marks[i]=0;    
        }      
    }
}

void TEST::average(){
    int sum=0,avg=0;
    for(i=0;i<n;i++){
        sum+=marks[i];
    }
    avg=sum/n;
    cout<<"\nThe average marks of the class is: "<<avg;
}

void TEST::highlow(){
    int high = marks[0];
    int low = marks [0];
    for(i=0;i<n;i++){
        high = max(high,marks[i]);
        low = min(low, marks[i]);
    }
    cout<<"\nThe highest and lowest marks of the students in the class are : "<<high<<" and "<<low<<" .\n";
}

void TEST::mostfreq(){
    int freq[n];
    for(i = 0; i<n ;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(marks[i]==marks[j]){
                count++;
            }
        }
        freq[i] = count;
    }
    int maxx=freq[0],maxx_index=0;
    for(i=0; i<n; i++){
        maxx=max(maxx,freq[i]);
        if(maxx==freq[i]){
            maxx_index=i;
        }
    }
    cout<<"\nMarks stored by most of the students is: "<<marks[maxx_index]<<"\n";
}

void TEST::absent(){
    cout<<"The list of the absent students in the test is as follows: \n";
    for(i=0;i<n;i++){
        if(attendance[i]==0){
            cout<<roll_no[i]<<"\t\t"<<name[i]<<endl;
        }
    }
}

int main(){
    TEST t;
    cout<<"FIRST TEST OF DSA\n";
    t.get_details();
    t.average();
    t.highlow();
    t.mostfreq();
    t.absent();
    return 0;
}