#include<iostream>
#include<string.h>
#include <conio.h>
using namespace std;

class node{
public:
	node *next;
	node *prev;
	int data;
	int seat;
	char name[10];
	char pass[10];
	node();
};

node :: node()
{
data=0;
next=NULL;
prev=NULL;
}

class Dlist{

node *head,*temp,*p;
public:
	Dlist();
	void cre();
	void book(int,int);
	void del(int , char* , char*);
	void display();

};

Dlist :: Dlist()
{
head = NULL;
}

void Dlist :: book(int r,int c)
{
temp=head;
for(int i=0;i<((r*7)+ c);++i)
{
	temp=temp->next;
}
if(temp->data==1)
{
    cout<<"\n Booking failed !!.Seat is already booked, Choose another seat.\n";
}
else {
	temp->data=1;
	cout<<"\n Enter name: \n";
	cin>>temp->name;
	cout<<"\n Create password: \n";
	cin>>temp->pass;
	cout<<"\n Booking Done.\n";
	temp->seat=((r*7) +c);
	cout<<"\n Your seat number: "<<temp->seat<<endl;
   }
}

void Dlist :: display()
{
temp=head;
int i=0;
cout<<"\n Seats Are displayed below:- \n";
cout<<"\n 0 for empty and 1 for booked ones. \n";
do{
if(i%7==0)
{
	cout<<endl;
}
cout<<temp->data<<"  ";
i++;
temp=temp->next;
}while(temp!=head);
cout<<endl;
}


void Dlist :: del(int a,char j[10],char k[10])
{
int g;
g=a;
temp=head;
while(a)
{
    temp=temp->next;
    a--;
}
if(temp->seat==g && (!strcmp(temp->name,j)) && (!strcmp(temp->pass,k)) && (temp->data==1))
{
	cout<<"\n Booking Canceled. \n";
	temp->data=0;
}
else cout<<"\n Cancellation Failed!!.\n";
}


void Dlist :: cre()
{
p=new node;
if(head==NULL)
{
	head=p;
	head->next=head->prev=head;
}
p->next=head;
p->prev=head->prev;
head->prev->next=p;
head->prev=p;
}

int main()
{

Dlist ob;
for(int i=0;i<70;++i)
{
	ob.cre();
}
ob.display();
int k;
int ch=1;
char sa[10],nh[10];
int d;
int r,c;
do{
cout<<"\n ***************************** MENU-STARTS************************************* \n";
cout<<"\n   What to do:- \n       1.Booking \n       2.Display\n       3.Cancel\n       4.exit\n";
cout<<"\n ***************************** MENU-ENDS*************************************** \n";
cout<<"\n Enter your choice:";
cin>>k;
switch(k)
{
case 1:do{
	cout<<"\n Enter row and column: \n";
	cin>>r>>c;
	if(r<0 || c<0 || r>9 || c>6)
        cout<<"\n Enter values of row between 0-9 and column between 0-6 \n";
	}while(r<0 || c<0 || r>9 || c>6);
	ob.book(r,c);
	break;
case 2: ob.display();
	break;
case 3:
    do
    {cout<<"\n Enter your seat number: \n";
	cin>>d;
	if(d<0 || d > 70)
        cout<<"\n Error!!!.Enter correct seat number.\n";
    }while(d<0 || d > 70);
	cout<<"\n Enter your name: \n";
	cin>>sa;
	cout<<"\n Enter your password: \n";
	cin>>nh;
	ob.del(d,sa,nh);
	break;
case 4: return -1;
default: cout<<"\n Error enter valid option!! \n";
	break;
}
}while(ch);
return 0;
}
