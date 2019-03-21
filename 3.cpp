#include<iostream>
using namespace std;

class Matrix
{
   public:
   int r,c;
   int mat[10][10];

    public:
    void Accept();
    void Upt();
    void Sde();
    void Tran();
    void Add(Matrix);
    void Sub(Matrix);
    void Mul(Matrix);
};

void Matrix :: Accept()
{

  do{
        cout<<"Enter the number of rows of the matrix : \n";
  cin>>r;

  cout<<"Enter the number of columns of the matrix : \n";
  cin>>c;
  if(r<0 || c<0)
    cout<<"\n Wrong input !!. \n";
  }while(r<0 || c<0);

   cout<<"Enter the elements of the matrix: \n";
   for(int i=0;i<r;i++)
   {
      for(int j=0;j<c;j++)
     {
       cout<<"Enter the element no [ "<<i<<" ][ " <<j <<" ] : \n";
       cin>>mat[i][j];
     }

  }
}

void Matrix :: Upt()
{
int flag=0;
int i,k=0;
if(r==c)
{
 for(i=0;i<r;i++)
   {
      for(int j=0;j<c;j++)
     {
       if(i>j)
        {
            if(mat[i][j]!=0)
                flag=1;
        }
     }
  }
if(flag==0)
    cout<<"It is an Upper triangular matrix \n";
    else
        cout<<"Not an upper triangular matrix \n";

}
else
cout<<"Not an upper triangular matrix \n";
}

void Matrix :: Sde()
{
int k=0;
if(r==c)
{
 for(int i=0;i<r;i++)
   {
      for(int j=0;j<c;j++)
     {
       if(i==j)
        k+=mat[i][j];
     }

  }
cout<<"Summation of diagonal elements is: "<<k<<endl;

}
else
cout<<"Can't find summation of Diagonal element because rows is not equal to columns \n";
}

void Matrix :: Tran()
{
int temp=0;

for(int i=0;i<r;i++)
   {
      for(int j=i;j<c;j++)
     {
    temp=mat[i][j];
	mat[i][j]=mat[j][i];
	mat[j][i]=temp;
     }

  }

for(int i=0;i<r;i++)
   {
      for(int j=0;j<c;j++)
     {
       cout<<mat[i][j]<<"   ";
     }
    cout<<"\n";
  }
}

void Matrix :: Add(Matrix m2)
{
if(r==m2.r && c==m2.c)
  {
    for(int i=0;i<r;i++)
     {
      for(int j=0;j<c;j++)
       {
          cout<<mat[i][j]+m2.mat[i][j]<<"  ";
       }
        cout<<endl;
    }
  }
}

void Matrix :: Sub(Matrix m2)
{
if(r==m2.r && c==m2.c)
  {
    for(int i=0;i<r;i++)
     {
      for(int j=0;j<c;j++)
       {
          cout<<mat[i][j]-m2.mat[i][j]<<"  ";
       }
        cout<<endl;
    }
  }
}

void Matrix :: Mul(Matrix m2)
{
    int i,j,k,sum=0;
    if(c==m2.r)
       {
            for(i=0;i<r;i++)
         {
           for(j=0;j<m2.c;j++)
           {
               for(k=0;k<m2.r;k++)
               {
                   sum+=mat[i][k]*m2.mat[k][j];
               }
               cout<<sum<<"  ";
               sum=0;
           }
                cout<<endl;
            }
            cout<<endl;
       }
}

int main()
{
int l;
char z;
Matrix m1;
Matrix m2;
m1.Accept();
m2.Accept();
do
{
cout<<"Enter choice from list: \n 1. Whether matrix first is upper triangular or not \n 2. Summation of Diagonal Elements of first matrix \n 3. Transpose of first Matrix \n 4. Addition of two matrix \n 5. Subtraction of first matrix by second Matrix \n 6. Multiplication of two matrix \n 7. Whether second matrix is upper triangular or not \n 8. Summation of Diagonal Elements of first matrix \n 9. Transpose of second Matrix \n 10. Subtraction of second matrix by first Matrix \n ";
cin>>l;
switch(l)
{
case 1:
{
m1.Upt();
break;
}
case 2:
{
m1.Sde();
break ;
}
case 3:
{
m1.Tran();
break;
}

case 4:
{
m1.Add(m2);
break;
}

case 5:
{
m1.Sub(m2);
break;
}

case 6:
    {
        m1.Mul(m2);
        break ;
    }

case 7:
{
m2.Upt();
break;
}
case 8:
{
m2.Sde();
break ;
}
case 9:
{
m2.Tran();
break;
}

case 10:
{
m2.Sub(m1);
break;
}

default :
{
cout<<"Wrong Input!! \n Enter valid option. \n";
break;
}
}
cout<<"Do you want to continue enter y?: \n";
cin>>z;
}while(z=='y'||z=='Y');
return 0;
}
