#include <iostream>

using namespace std;
struct node{
int data;
int prior;
node *next;
};

class queque{
node *front,*rear;
public:
    queque(){
    front=NULL;
    rear=NULL;
    }

    void enque(int val,int pr){
     node *newn=new node;
        newn->data=val;
        newn->next=NULL;
        newn->prior=pr;
        if(front==NULL){
            front=newn;
            rear=newn;

        }
        else if( pr<front->prior){
            front=newn;
        }
        else{
                node *temp2=front;
       // temp2=front;
        while(temp2->next!=NULL && temp2->next->prior<=pr) {

            temp2=temp2->next;
        }
        newn->next=temp2->next;
            temp2->next=newn;
           /* if(newn->next==NULL){
            rear=newn;
            }*/
        }
        newn=NULL;
    }

    int deque(){
    if(front!=NULL){
        int k;
        node *temp;
        temp=front;
        k=front->data;
        front=front->next;
        delete temp;
        return k;
    }
    }
};
int main()
{
    queque abc;
    abc.enque(64,1);
    abc.enque(55,5);
    abc.enque(62,3);
    abc.enque(12,2);
    abc.enque(1,4);
    abc.enque(68,1);
    abc.enque(11,1);
    abc.enque(63,3);
    abc.enque(109,4);
    //abc.enque(55,6);
    cout<<abc.deque()<<endl;
    cout<<abc.deque()<<endl;
    cout<<abc.deque()<<endl;
    cout<<abc.deque()<<endl;
    cout<<abc.deque()<<endl;
    cout<<abc.deque()<<endl;
    cout<<abc.deque()<<endl;
    cout<<abc.deque()<<endl;
    cout<<abc.deque()<<endl;
    return 0;
}
