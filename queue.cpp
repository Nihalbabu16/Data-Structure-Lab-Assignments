#include<iostream>

using namespace std;

class node{
public :
    char data;
    node *next;
};

class Queue{
public :
	node *front,*rear,*temp,*start;
	void init();
	void enqueue();
	void dequeue();
	int isempty();
	void display();
};

void Queue::init()
{
    front=rear=start=temp=NULL;
}

void Queue::enqueue()
{
    temp = new node;
    cout<<"\nEnter the data for the Queue:\n";
    char da;
    temp->data = da;
    temp->next = NULL;
    if(front == NULL){
        front = rear = temp;
        rear->next = NULL;
    }
    else{
        rear->next = temp;
        rear = temp;
        rear->next = NULL;
    }
}

void Queue::dequeue()
{
    if(front == NULL )
    {
        cout<<"queue is empty\n";
        return;
    }
    else
    {
        start = front;
        front = front->next;
        delete(start);
        cout<<"Element deleted successfully.\n";
    }
}

int Queue::isempty()
{
    if(front == NULL || rear== NULL)
    	return 1;
    else
    	return 0;
}

void Queue::display(){
	node * temp=front;
	if(front == NULL)
    {
        cout<<"empty queue\n";
        return;
    }
    while(temp!=NULL)
    {
    	cout<<front->data<<"    ";
    	temp=temp->next;
    }
}

int main(){
    int n,k;
    Queue q;
    q.init();
    char cha,x;
	do{
        int ch;
        cout<<"\t************MENU**********\n"<<"1.For enqueue a node\n"<<"2.dequeue element a node\n"<<"3.Display the queue "<<endl;
        cin>>k;
        switch(k){
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        default:
            cout<<"\nEntered valid input\n"<<endl;
            break;

        }
        cout<<"Do you want to continue?\n"<<endl;
        cin>>cha;
	}
	while(cha=='y'||cha=='Y');
return 0;
}
