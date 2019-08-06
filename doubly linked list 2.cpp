#include <iostream>

using namespace std;

struct node{
int data;
node *next;
node *prev;
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
            temp->prev=NULL;
        head=temp;
        tail=temp;
    }
    else {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
 }
     void display(){
    node *temp=new node;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    }

    void del(int val){

    node *temp,*temp2,*temp3;
    temp=head;
    while(temp!=NULL){
        if(temp->data==val){
            //temp2=temp2->next;
            break;
        }
    temp2=temp;
      temp=temp->next;
        //temp2=temp->next;
    }

    temp3=temp2->prev;

    //inn 3 line ki waise zaroorat nahi but galti se while loop ek extra time chal gya toh
    temp=temp->next;
    temp2=temp2->next;
    temp3=temp3->next;

    temp3->next=temp;
    temp->prev=temp3;
    temp2->next=NULL;
    temp2->prev=NULL;
    delete temp2;
    }

};

int main(){

    list abc;
    abc.createnode(5);
    abc.createnode(15);
    abc.createnode(25);
    abc.createnode(35);
    abc.createnode(45);
    abc.createnode(55);
    abc.createnode(65);
    abc.createnode(75);
    abc.del(45);
    //abc.swapconpos(4);
    abc.display();
    return 0;
}
