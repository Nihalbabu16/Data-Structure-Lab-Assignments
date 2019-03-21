//*****linear sort

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter number of elements in array";
    cin>>n;
int a[n];
cout<<"\nEnter "<<n <<" elements which needed to be sort\n";

for(int i=0;i<n;i++)
{
cin>>a[i];
}

cout<<"\n Entered array.\n";
for(int i=0;i<n;i++)
cout<<a[i]<<"   ";

int temp;
for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        if(a[i]<a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
cout<<"\nSorted array.\n";
for(int i=0;i<n;i++)
    cout<<a[i]<<"  ";

return 0;
}
