#include <iostream>

using namespace std;
struct node{
int data;
node *next;
};

class queque{
node *front,*rear;
public:
    queque(){
    front=NULL;
    rear=NULL;
    }

    void enque(int val){
     node *temp=new node;
        temp->data=val;
        temp->next=front;
        if(front==NULL){
            front=temp;
            rear=temp;

        }
        else{
            rear->next=temp;
            rear=temp;
        }
        temp=NULL;
    }

    int deque(){
    if(front!=NULL){
        int k;
        node *temp;
        temp=front;
        k=front->data;
        front=front->next;
        rear->next=front;
        delete temp;
        return k;
    }
    }
};
int main()
{
    queque abc;
    abc.enque(5);
    abc.enque(15);
    abc.enque(25);
    abc.enque(35);
    abc.enque(45);
    abc.enque(55);
    cout<<abc.deque();
    cout<<abc.deque();
    cout<<abc.deque();
    cout<<abc.deque();
    cout<<abc.deque();

    return 0;
}
