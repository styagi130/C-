#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
} *Head;

class linked_list
{
	public:
		void INIT(int x,int n);
		void print();
		int length();
		void delete1(int n);
		void reverse();
		void sort(Node *x);
};
int linked_list::length(){
	Node * temp=Head;
	int leng=0;
	while (temp!=NULL){
		leng+=1;
		temp=temp->next;
}
	return leng;
}
void linked_list::INIT(int x,int n)
{	int k=length();
	if (n>k+1){
	n=k+1;
	}
	if (n==1){
	Node* temp=(Node*)new(Node);
	temp->data=x;
	temp->next=Head;
	Head=temp;
	cout<<"Done"<<endl;
	}
	else{
		Node * temp1=Head;
		for (int i=0;i<n-2;i++){
			temp1=temp1->next;
		}
		Node* temp=(Node*)new(Node);
		temp->data=x;
		temp->next=temp1->next;
		temp1->next=temp;
		cout<<"Done"<<endl;
	}
}

void linked_list::print(){
Node *  temp=Head;
while (temp!=NULL){
cout<<temp->data<<endl;
temp=temp->next;
}
}


void linked_list::delete1(int n){
	Node * temp = Head;
	if (n==0)
	{
		Node * temp1=temp->next;
		Head=temp1;
	}
	else{
		for (int i=0;i<n-1;i++){
			temp=temp->next;
			cout<<"Okay working"<<endl;
		}
		Node * temp1=temp->next;
		temp->next=temp1->next;
}
}

void linked_list::reverse()
{
	Node * current,*prev,*next1;
	current=Head;
	prev=NULL;
	next1=NULL;
	while (current->next!=NULL)
	{
		cout<<"YES"<<endl;
		next1=current->next;
		current->next=prev;
		prev=current;
		current=next1;
	}
	current->next=prev;
	Head=current;
}

void linked_list::sort(Node *x){
	Node* temp,* prev;
	temp=x;
	Node* next1=temp->next;
	while (temp->next!=NULL){
		if (temp->data<next1->data){
			Node *swap;
			swap=next1->next;
			next1->next=temp;
			temp->next=swap;
		}
		sort(temp);
	}
}
int main() 
{
Head=NULL;
linked_list ls;
ls.INIT(4,1);
ls.INIT(2,1);
ls.INIT(1,1);
ls.INIT(3,1);
ls.print();
std::cout<<"length of linked list is "<<ls.length()<<endl;
ls.sort(Head);
ls.print();
cout<<"length of new linked list is "<<ls.length()<<endl;
return 0;
}
