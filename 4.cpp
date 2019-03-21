#include<iostream>
#include<string>

using namespace std;

class Node{
	int prn;
	string name;
	public:
	Node *next;
	Node();
	string retStr();
	int retPrn();
};

class Club{
	Node *head;
	void createPresident();
	void createMember();
	void createSecretory();
	void removePresident();
	void removeSecretory();
	void removeMember(int);
	void rec(Node *);
	public:
	Club();
	void crea();
	void del();
	void disp();
	void counter();
	void operator +(Club);
};

string Node::retStr(){
	return name;
}

int Node::retPrn(){
	return prn;
}

Node::Node(){
	cout<<"\nEnter PRN : ";
	cin>>prn;
	cout<<"\nEnter Name : ";
	cin>>name;
	next = NULL;
}

void Club::removePresident(){
	if(head == NULL){
		cout<<"\nERROR : Empty list\n";
		return;
	}
	Node *p;
	p = head;
	head = head->next;
	delete p;
	cout<<"\nDeleated President\n";
}

void Club::removeSecretory(){
	if(head == NULL){
		cout<<"\nERROR : Empty list\n";
		return;
	}

	if(head->next == NULL){
		cout<<"\nERROR : No Secretory\n";
		return;
	}

	Node *start;
	start = head;
	while(start->next->next != NULL){
		start = start->next;
	}

	Node *p;
	p = start->next;
	delete p;
	start->next = NULL;
	cout<<"\nDeleated Secretory\n";
}

void Club::removeMember(int a){
	if(head == NULL){
		cout<<"\nERROR : Empty list\n";
		return;
	}

	if(head->next == NULL){
		cout<<"\nERROR : No Secretory\n";
		return;
	}

	if(head->next->next == NULL){
		cout<<"\nERROR : No Members in list\n";
		return;
	}

	Node *start;

	start = head;
	while(start->next->next->next != NULL){
		if(start->next->retPrn() == a){
			break;
		}
		start = start->next;
	}

	if(start->next->retPrn() != a){
		cout<<"\nERROR : NO Member With PRN = "<<a<<" Found\n";
		return;
	}


	Node *p;
	p = start->next;
	start->next = p->next;
	delete p;
	cout<<"\nDeleted Member\n";
}

void Club::createPresident(){
	cout<<"\nEnter President Details :-\n";
	Node *temp = new Node;
	Node *start;
	temp->next = head;
	head = temp;
	temp=temp->next;
}

void Club::createMember(){
	if(head == NULL){
		cout<<"\nError NO President\n";
		return;
	}

	if(head->next == NULL){
		cout<<"\nError : NO Secretory\n";
		return;
	}

	Node *start;
	start = head;
	Node *temp = new Node;
	while(start->next->next != NULL){
		start = start->next;
	}
	temp->next = start->next;
	start->next = temp;
}

void Club::createSecretory(){
	if(head == NULL){
		cout<<"\nError NO President\n";
	}
	else{
		Node *start;
		Node *temp = new Node;
		start = head;
		while(start->next != NULL){
			start = start->next;
		}
		start->next = temp;
	}
}

void Club::crea(){
	int t;
	cout<<"\n1.Make President\n2.Make Member\n3.Make Secretory\nEnter CHOICE : ";
	cin>>t;
	switch(t){
	case 1: createPresident();
		break;
	case 2: createMember();
		break;
	case 3: createSecretory();
		break;
	default:cout<<"\nError\n";
	}
}

void Club::del(){
	int t;
	cout<<"\n1.Remove President\n2.Remove Member\n3.Remove Secretory\nEnter CHOICE : ";
	cin>>t;
	int a;
	switch(t){
	case 1: removePresident();
		break;
	case 2:
		cout<<"\nEnter PRN Number of the user to be deleated : ";
		cin>>a;
		removeMember(a);
		break;
	case 3: removeSecretory();
		break;
	default:cout<<"\nError\n";
	}
}

void Club::disp(){
	if(head == NULL){
		cout<<"\nEMPTY List\n";
		return;
	}
	rec(head);
	cout<<"\n********************END OF LIST********************\n";
}

void Club::rec(Node *p){
	if(p == NULL){
		cout<<"\n********************START OF LIST********************\n";
		return;
	}
	rec(p->next);
	cout<<"\nPRN : "<<p->retPrn()<<"\nNAME : "<<p->retStr()<<endl;
}

void Club::counter(){
	int count = 0;
	Node *start = head;
	while(start != NULL){
		++count;
		start = start->next;
	}
	if(count == 0)
		cout<<"\nEmpty\n";
	else
		cout<<"\nThe Number Of Members Are : "<<count<<endl;
}

void Club::operator +(Club c){
	Node *start;
	start = head;
	cout<<"\nThe 2 Lists have been joined and given to Comp1\n";
	if(start == NULL&&c.head==NULL){
		head = c.head;
	}
	while(start->next != NULL){
		start = start->next;
	}
	start->next = c.head;
}

Club::Club(){
	head = NULL;
	createPresident();
}

main(){
	cout<<"\nMaking Club for Comp 1 :-\n";
	Club c1;
	cout<<"\nMaking Club for Comp 2 :-\n";
	Club c2;
	char p;
	do{
		cout<<"\n1.Add Someone in Comp1\n2.Remove Someone from Comp1\n3.Display Comp1\n4.Count Total Members In Comp1\n5.Add Someone in Comp2\n6.Remove Someone from Comp2\n7.Display Comp2\n8.Count Total Members In Comp2\n9.Join the two Clubs\nEnter Your CHOICE : ";
		int x;
		cin>>x;
		switch(x){
		case 1 :c1.crea();
			break;
		case 2 :c1.del();
			break;
		case 3 :c1.disp();
			break;
		case 4 :c1.counter();
			break;
		case 5 :c2.crea();
			break;
		case 6 :c2.del();
			break;
		case 7 :c2.disp();
			break;
		case 8 :c2.counter();
			break;
		case 9 :c1 + c2;
			c1.disp();
			break;
		default :cout<<"\nERROR\n";
		}
		cout<<"Do You Want To CONTINUE(y/n) : ";
		cin>>p;
	}while(p=='y'||p=='Y');
	return 0;
}
