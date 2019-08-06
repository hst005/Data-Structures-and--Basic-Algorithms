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

    node *gethead(){
    return head;
    }
     void insertnode(int val){
     node *temp=new node;
     temp->data=val;

    temp->next=NULL;
     if (head==NULL){
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
        while (temp!=NULL) {
            cout<<temp->data<<endl;
            temp=temp->next;
            }
     }

     void insertstart(int val){
     node *temp=new node;
     temp->data=val;
     head->prev=temp;
     temp->next=head;
     temp->prev=NULL;
     head=temp;
     }

     void delbypos(int pos){
     node *temprev=new node;
     node *temp1=new node;
     node *tempdel=new node;
     temprev=head;
     for(int i=0;i<pos-2;i++){
        temprev=temprev->next;
     }
     tempdel=temprev->next;
     temp1=temprev->next->next;
     temprev->next=temp1;
     temp1->prev=temprev;
     delete tempdel;
     }

     void swap(int pos1,int pos2){
    node *temp1=new node;
    node *temp2=new node;
    temp1=head;
    temp2=head;
        for(int i=0;i<pos1-2;i++){
        temp1=temp1->next;
     }
     for(int j=0;j<pos2-2;j++){
        temp2=temp2->next;
     }

       node *temp1prev=new node;
    node *temp2prev=new node;
       node *temp1next=new node;
    node *temp2next=new node;
     temp1prev=temp1->prev;
     temp2prev=temp2->prev;
     temp1next=temp1->next;
     temp2next=temp2->next;

     temp1->next=temp2next;
     temp2next->prev=temp1;
     temp1->prev=temp2prev;
     temp2prev->next=temp1;

     temp2->next=temp1next;
     temp2->prev=temp1prev;
     temp1next->prev=temp2;
     temp1prev->next=temp2;

        }

        void revtry2(){
            struct node *p1, *p2;
        p1 = head;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    head = p1;
    cout<<"List Reversed"<<endl;
    }
/*
        void revers(){
        node *temp=new node;
        node *temp1=new node;
        temp=tail;
        while(temp!=NULL){
            temp1=temp->prev;
            temp->prev=temp->next;
            temp->next=temp1;
            //temp=temp->prev;
            temp=temp1;
        }
        if(temp != NULL )
        head = temp->prev;
        }

*/

     void delno(int val){
     node *temp=new node;
     node *temprev=new node;
     node *temp1=new node;
     temp=head;
     while(temp!=NULL){
        if(temp->data==val)
            break;
        temp=temp->next;
     }

     temprev=temp->prev;
     temp1=temp->next;

     temprev->next=temp1;
     temp1->prev=temprev;
     delete temp;
     }

     /*or
     void delno(int val){
     node *temp=new node;
     node *temprev=new node;
     node *temp1=new node;
     temp=head;
     while(temp!=NULL && temp->data!=val){
        temp=temp->next;

     }

     temprev=temp->prev;
     temp1=temp->next;

     temprev->next=temp1;
     temp1->prev=temprev;
     delete temp;
     }
*/
void newtry(){
cout<<head->next->data;
}

node *Revrec(node *nod)
{
    //notworking
    // If empty list, return
    if (!nod)
        return NULL;

    // Otherwise, swap the next and prev
    node *temp = nod->next;
    nod->next = nod->prev;
    nod->prev = temp;

    // If the prev is now NULL, the list
    // has been fully reversed
    if (!nod->prev)
        return nod;

    // Otherwise, keep going
    return Revrec(nod->prev);
}

};
int main()
{
   list abc;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
    int m;
    cin>>m;
    abc.insertnode(m);
   }/*
   abc.insertnode(5);
   abc.insertnode(15);
   abc.insertnode(25);
   abc.insertnode(35);
   abc.insertstart(2);
   */
   abc.newtry();
   cout<<endl;
   abc.display();
   //abc.reverse1(abc.gethead());
   //abc.revers();
   abc.revtry2();
    abc.display();
   cout<<"which pos element to delete";
   int l;
   cin>>l;
   abc.delbypos(l);
   abc.display();
   cout<<"which  element to delete";
   int k;
   cin>>k;

   abc.delno(k);
   abc.display();
/*
   int g,h;
   cout<<"which pos to swap";
   cin>>g>>h;
   abc.swap(g,h);
   abc.display();

   int o,p;
   cout<<"which pos to swap";
   cin>>o>>p;
   abc.swap(o,p);
   abc.display();
 int t,y;
   cout<<"which pos to swap";
   cin>>t>>y;
   abc.swap(t,y);
   abc.display();

*/
    //abc.revtry2();
    //abc.display();

    abc.Revrec(abc.gethead());
    abc.display();
    return 0;
}
