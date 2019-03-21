//*******binary search

#include<iostream>
using namespace std;

int bsear(int a[], int l,int r , int k)
{
     int mid;
if(r>=1)
{
    mid = l+ (r-l)/2;

    if(a[mid]==k)
    {
        cout<<"\nElement found!!\n";
        return mid;
    }
    if(a[mid]>k)
        return bsear(a,l,mid-1,k);

    if(a[mid]<k)
           return  bsear(a,mid+1,r,k);
}
else if(mid<1)
{
    cout<<"Element not found.";
    return mid;
}
else return 0;

}

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

int flag = bsear(a,0,n-1,k);
if(flag==0)
        cout<<"\nElement not found!!!.\n";
else
       cout<<"\nElement found at index "<<flag<<" .\nNote index of starting element is 0!!!"<<endl;


return 0;
}
