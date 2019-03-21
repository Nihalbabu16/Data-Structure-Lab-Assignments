//***sentinel search

#include<iostream>
using namespace std;

int main()
{
int n;
cout<<"\nEnter the number of students\n";
cin>>n;
int a[n];
cout<<"\nEnter the roll no of "<<n<<" students\n";
for(int i=0;i<n;i++)
cin>>a[i];

int k;
cout<<"\nEnter the roll no that need to be find\n";
cin>>k;
int flag=0;
if(a[n-1]==k)
{
    cout<<"\nElement found at index "<<n-1<<"\nNote index of starting element is 0!!!"<<endl;
    return 0;
}
int last =a[n-1];
a[n-1]=k;

for(int i=0;i<n-1;i++)
{
if(a[i]==a[n-1])
    {
    cout<<"\nElement found at index "<<i<<"\nNote index of starting element is 0!!!"<<endl;
    flag=1;
    break;
    }
}
if(flag==0)
    cout<<"\nElement not Found!!!";
return 0;
}
