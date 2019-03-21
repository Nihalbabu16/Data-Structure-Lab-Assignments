#include<iostream>
using namespace std;

class node{
public:
    int exp;
    float coeff;
    node *next;
    int rexp();
    float rcoeff();
};

int node :: rexp()
{
return exp;
}

float node :: rcoeff()
{
return coeff;
}

class Poly : public node
{
public:
    node *head,*temp,*start,*p;
    Poly();
    node* cre(int n);
    void input();
    void dis();
    void add(Poly);
    //void sub();
    //void mul();

};

void Poly ::dis()
{
    node * ptr;
    ptr = this->head;
    while(ptr!=NULL)
    {
       cout<<ptr->coeff<<"X^"<<ptr->exp<<" + ";
       ptr=ptr->next;
    }
    cout<<" 0 = 0"<<endl;
}

Poly :: Poly ()
{
head = NULL;
}

node* Poly :: cre(int n)
{
    head = new node;
    temp = head;
    cout<<"\nEnter the exponent: ";
    cin>>head->exp;
    cout<<"\nEnter the coefficient: ";
    cin>>head->coeff;
    head->next = NULL;
    temp =head;
    for(int i=1;i<n;++i)
      {
      start = new node;
      cout<<"\nEnter the exponent: ";
        cin>>start->exp;
        cout<<"\nEnter the coefficient: ";
        cin>>start->coeff;
      temp->next = start;
      start->next = NULL;
      temp = start;
       }
return (head);
}

void Poly :: add(Poly p2)
{
Poly p3;
this->temp=this->head;
p2.temp=p2.head;
while(this->temp!=NULL && p2.temp!=NULL)
{
        p3.temp = new node;
        p3.temp->next = p3.head;
        p3.head = p3.temp;

      if(this->temp->exp > p2.temp->exp)
      {
        p3.temp->exp = this->temp->exp;
        p3.temp->coeff = this->temp->coeff;
        this->temp = this->temp->next;
        continue;
      }
     if(p2.temp->exp > this->temp->exp)
      {
        p3.temp->exp = p2.temp->exp;
        p3.temp->coeff = p2.temp->coeff;
        p2.temp=p2.temp->next;
        continue;

      }
      if(p2.temp->exp == this->temp->exp)
      {
        p3.temp->exp = this->temp->exp;
        p3.temp->coeff = this->temp->coeff + p2.temp->coeff;
        this->temp = this->temp->next;
        p2.temp=p2.temp->next;
      }
}

while(this->temp!=NULL)
{
	p3.temp = new node;
	p3.temp->next = p3.head;
	p3.head = p3.temp;
	p3.temp->exp = this->temp->exp;
	p3.temp->coeff = this->temp->coeff;
	this->temp = this->temp->next;
}

while(p2.temp!=NULL)
{
        p3.temp = new node;
        p3.temp->next = p3.head;
        p3.head = p3.temp;
        p3.temp->exp = p2.temp->exp;
        p3.temp->coeff = p2.temp->coeff;
        p2.temp = p2.temp->next;
}
p3.dis();
}

int main()
{
Poly p1,p2,p3;
int n1,n2;
cout<<"\n Enter the number of node for first polynomial you want to enter: ";
cin>>n1;
p1.head=p1.cre(n1);
p1.dis();
cout<<"\n Enter the number of node for second polynomial you want to enter: ";
cin>>n2;
p2.head=p2.cre(n2);
p2.dis();
p1.add(p2);
return 0;
}
