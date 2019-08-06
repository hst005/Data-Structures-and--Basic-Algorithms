#include <iostream>

using namespace std;
struct node{
int data;
node *next;
};

class clist{
public:
node *head,*tail;
clist(){
head=NULL;
tail=NULL;
}

void insert(int val){
node *temp=new node;
temp->data=val;


if(head==NULL){
   head=temp;
   tail=temp;

   }
   else {
        tail->next=temp;
        tail=temp;
   }
   tail->next=head;
}

void display(){
node *temp;
temp=head;
while(temp->next!=head)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
};
int main()
{
    clist abc;
    abc.insert(5);
    abc.insert(15);
    abc.insert(25);
    abc.insert(35);
    abc.display();
    return 0;
}
