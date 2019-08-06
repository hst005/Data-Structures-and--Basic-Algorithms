#include <iostream>

using namespace std;
struct node{
int data;
node *next;
};

class clist{
public:
node *tail;
clist(){
//head=NULL;
tail=NULL;
}
void insert(int val){
node *temp=new node;
temp->data=val;

    if (tail == NULL)
    {
        tail = temp;
        temp->next = tail;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
}
void display(){
node *temp;
temp=tail->next;
while(temp->next!=tail->next)
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
