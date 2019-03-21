#include<iostream>

using namespace std;

class Students{

int cric[60];
int badm[60];
int uni;
int z;

void input()
	{
		int x,y;
		cout<<"enter total student in class";
		cin>>z;
		cout<<"enter number of students who play cricket";
		cin>>x;
		cout<<"enter roll number of students who play cricket";
		int temp;
		for(int i=0;i<x;i++)
		{
		 cin>>temp;
		 cric[temp] = 1;
		 }
		cout<<"enter number of students who play badminton";
		cin>>y;
		cout<<"enter roll number of students who play badminton";
		for(int i=0;i<y;i++)
		{
		 cin>>temp;
		 badm[temp] = 1;
		}
	}

public:

Students(){
	for(int i=0;i<60;++i){
		cric[i] = 0;
		badm[i] = 0;
	}
	input();
}

void intersection()
	{
		cout<<"Students who plays both the games \n";

	  for(int i=0;i<60;i++)
	  	{
	  	if((cric[i]==1)&&(badm[i]==1))
	  		cout<<i<<" ";
	}
	cout<<endl;
	}

void onlyc()
	{ int f;
	cout<<"\n only cric \n";
	 for(int i=0;i<60;i++)
	 {
	 if((cric[i]==1)&&(badm[i]==0))
	  		cout<<i<<" ";
	}
	cout<<endl;
	}

void onlyb()
	{
	   cout<<"\n only b \n";
	for(int i=0;i<60;i++)
	 {
	if((cric[i]==0)&&(badm[i]==1))
	  		cout<<i<<" ";
	 }
	 cout<<endl;
	}

void cbb()
	{
	int a = 0;
	cout<<"\n c,b & both \n";
	for(int i=0;i<60;i++)
		if((cric[i]==1)||(badm[i]==1)){
			cout<<i<<"  ";
			++a;
		}
	uni = a;
	cout<<endl;
	}
void calc(){
	cout<<"\nHow many DONT Play Anything : "<<z-uni<<endl;
	 {	for(int i=1;i<z+1;i++)

	if((cric[i]==0)&&(badm[i]==0))
	  		cout<<i<<" ";
	 }
}
};

main(){
Students s;
s.intersection();
s.onlyc();
s.onlyb();
s.cbb();
s.calc();
return 0;
}
