#include<iostream>
using namespace std;
class Student{
public:
  char name[10];
  int mark;
public:
  void input();
};

void Student::input()    //taking name and marks
{
cout<<"Enter name \n";
cin>>name;
cout<<"Enter the marks \n";
cin>>mark;
while(mark<-1 || mark>100)
{
    cout<<"Wrong input!.Enter again \n";
    cin>>mark;
}

}

int mx(int mr[],int x)    //finding max mark
{
int i,temp,maximum=-1;
for(i=0;i<x;i++)
{
    if(mr[i]>-1)
      {
          if(maximum<mr[i])
            maximum=mr[i];

      }

}
return maximum;
}

int mn(int mr[],int x)    //finding min mark
{
int i,temp,minimum=mr[0];
for(i=1;i<x;i++)
{
    if(mr[i]>-1)
      {
          if(minimum>mr[i])
            minimum=mr[i];

      }

}
cout<<"in min loop: "<<minimum;
return minimum;
}

float avg(int mr[],int x)      //finding average
{
  float sum=0;
  int i;
  float average;
    for(i=0;i<x;i++)
    {
      if(mr[i]>-1)
      sum+=mr[i];
    }
  average=sum/x;
  return average;
}

int mscore(int mr[],int x)
{
   int ar[11]={0};
   int i,k,l,m=0;
   for(i=0;i<x;i++)
   {
       if(mr[i]>0)
      {
          k=mr[i]/10;
         ar[k]++;
    }
   }
  for(i=0;i<11;i++)
   {
      if(m<ar[i])
        {   m=ar[i];
            l=i;
        }
   }
   return l;
}


int main()
{
    int x,f;
    char g;

do
    {
    cout<<"Enter no of student";
    cin>>x;
    int i;
    Student s[x];
    for(i=0;i<x;i++)
    {
       s[i].input();
    }
    int mr[x]={0};
    for(i=0;i<x;i++)
      mr[i]=s[i].mark;


cout<<"Enter choice \n 1.For Average \n 2.For Highest AND  Lowest \n 3.Marks scored by most of the Students\n 4.List of absent student. \n";
cin>>f;

switch(f)
{
case 2:
{
int maxn;
maxn=mx(mr,x);
cout<<"Highest Marks:  "<<maxn;

int minn;
minn=mn(mr ,x);
cout<<"Lowest Marks:  "<<minn;
break ;
}

case 1:
{
float avgn;
avgn = avg(mr,x);
cout<<"Average Marks: "<<avgn;
break ;

}

case 3:
{
int mscoren;
mscoren=mscore(mr,x);
mscoren=mscoren*10;
cout<<"Marks scored by maximum students in class lies between : "<<mscoren<<" - "<<(mscoren+10)<<endl;
break;
}

case 4:
{
for(i=0;i<x;i++)
{
   if(s[i].mark==-1)
    cout<<"List of students who were absent: "<<s[i].name<<endl;

}
break;
}

default:
cout<<"Enter valid option!! \n";
}
cout<<"For continue enter y \n";
cin>>g;
}while(g=='y' || g== 'Y');
return 0;
}
