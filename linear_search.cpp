//****linear search

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
for(int i=0;i<n;i++)
{
    if(a[i]==k)
        {
            cout<<"\nElement found at index "<<i<<"\nNote index of starting element is 0!!!"<<endl;
            flag=1;
        }
}

if(flag==0)
    cout<<"\nElement not Found!!!";

return 0;
}
