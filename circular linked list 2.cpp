#include <iostream>

using namespace std;
struct node{
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
        temp->next=head;
        if(head==NULL){
            head=temp;
            tail=temp;

        }
        else{
            tail->next=temp;
            tail=temp;
        }
        temp=NULL;
    }
     void display(){
    node *temp=new node;
    temp=head;
        cout<<temp->data<<endl;
        temp=temp->next;

    while(temp!=head){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    }
};

int main()
{
        list abc;
    abc.createnode(5);
    abc.createnode(15);
    abc.createnode(25);
    abc.createnode(35);
    abc.createnode(45);
    abc.createnode(55);
    abc.createnode(65);
    abc.createnode(75);
    //abc.swapconpos(4);
    abc.display();


    return 0;
}
