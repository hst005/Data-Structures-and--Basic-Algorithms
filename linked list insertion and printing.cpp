#include <iostream>

using namespace std;


class node{
public:
int data;
 node *next;

 node *start=NULL;

 node* createnode(){
node *temp;
temp=new node();
return temp;
}

void insertnode(){
node *temp,*traverse;
int n;
cout<<"-1 to end"<<endl;
cin>>n;
while(n!=-1)
    {
        temp=createnode();
        temp->data=n;
        temp->next=NULL;

        if(start==NULL){
            start=temp;
        }
        else{
            traverse=start;
            while(traverse->next!=NULL)
            {
                traverse=traverse->next;
            }
            traverse->next=temp;
        }
    }
    cin>>n;
}

void printlist(){
node *traverse=start;
while(traverse!=NULL){
      cout<<traverse->data<<endl;
      traverse=traverse->next;
      }
}

};
int main()
{
node abc;
        abc.insertnode();
    return 0;
}
