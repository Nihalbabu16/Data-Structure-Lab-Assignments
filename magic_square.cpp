#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

void msqr()
{
int n;
    do{
        cout<<"\nEnter the size of magic square: \n(Note enter odd number only!!!!)\n";
        cin>>n;
        if(n<=1 || n%2 == 0)
            cout<<"\nError entered value of magic square size is wrong.\nEnter correct value!!!.";
    }while(n<=1 || n%2 == 0);

int a[n][n];

for(int d=0;d<n;d++)
    for(int e=0;e<n;e++)
        a[d][e]=0;

int i = n/2;
int j = n-1;

for(int k=1;k<=n*n; )
{
    if(i==-1 && j==n)
        {
            j=n-2;
            i=0;
        }
    else{
        if(j==n)
            j=0;

        if(i<0)
            i=n-1;
    }
    if (a[i][j])
            {
                j = j-2;
                i++;
                continue;
            }
    else
        a[i][j] = k++;

    j++;
    i--;
}


cout<<"\n\n\n\n\nThe Magic Square for "<< n <<"\nSum of each row or column or diagonal should be = "<<n*(n*n+1)/2<<"\n";
cout<<"\n**************MAGIC SQUARE*************\n";
for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        cout<<a[i][j]<<"  ";
    cout<<endl;
    }
}

int main()
{
msqr();
return 0;
}
