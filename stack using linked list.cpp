#include<iostream>
using namespace std;

#define max 100

struct node {
int data;
node *next;
};

class list{
node *head,*tail;



public:
list(){
head=NULL;
tail=NULL;
}
void createnode(int val){
node *temp=new node;
temp->data=val;
temp->next=NULL;
if(head==NULL){
head=temp;
tail=temp;
temp=NULL;
}
else {
tail->next=temp;
tail=tail->next;
}
}
void disp(){
node *temp=new node;
temp=head;
while(temp!=NULL){
cout<<temp->data<<"  ";
temp=temp->next;
}
}

void dispcurr(int pos){
node *temp=new node;
temp=head;
for(int i=0;i<pos;i++){
//cout<<temp->data<<"  ";
temp=temp->next;
}
cout<<temp->data<<endl;
}


void insertfirst(int value){
	node *temp=new node;
	temp->data=value;
	if(head==NULL){
		temp->next=NULL;
		head=temp;
		tail=temp;
		temp=NULL;
	}
	else {
		temp->next=head;
		head=temp;
		temp=NULL;
	}
}
void insertmid(int value,int pos){
	pos=pos-1;
	node *temp=new node;
		node *temp2=new node;
			node *temp3=new node;
	temp=head;
	for(int i=0;i<pos;i++){
		temp=temp->next;
	}
	temp2=temp->next;
	temp3->data=value;
	temp3->next=temp2;
	temp->next=temp3;
}

void del(int val){
		node *temp=new node;
		temp=head;
		int a=0,b=0;
		while(temp!=NULL){
			a+=1;
			if (temp->data==val){
				b=1;
				break;
			}
		}
		if (b==1){
		for(int i=0;i<a-1;i++){
			temp=temp->next;
		};
		node *temp2=new node;
		temp2=temp->next;
				temp->next=temp->next->next;
				//temp->next=temp2->next;
				delete temp2;
}
else {
	cout<<"not found";
}
}

};

class stack{
int top;
list a;
public:
stack(){
top=0;
}

bool isempty(){
if(top==0)
return true;
return false;
}

bool isfull(){
if(top==max)
return true;
return false;
}

void push(int val){
if(top<max){
a.insertfirst(val);
top++;
}
}

void pop(){
top--;
a.dispcurr(top);

}

};

int main(){
stack abc;
abc.push(5);
abc.push(10);
abc.push(15);
abc.pop();
abc.pop();
abc.pop();

//abc.pop();
return 0;
}
