#include <iostream>
using namespace std;
 struct node
  {
    int data;
    node *next;
  };
    class list
  {

    node *head, *tail;
    public:
    list()
    {
      head=NULL;
      tail=NULL;
    }

   void createnode(int value)
    {
      node *temp=new node;
      temp->data=value;
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {
        tail->next=temp;
        tail=temp;
      }
    }
    void display()
  {
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<"\t";
      temp=temp->next;
    }
  }
  void insertstart(int d){
      node *temp=new node;

      temp->data=d;
      temp->next=head;
        head=temp;

  }
  void insertendm1(int d){
      node *temp=new node;
      temp=head;
      while(temp->next!=NULL){
        temp=temp->next;
      }
      node *ab=new node;
      temp->next=ab;
      ab->data=d;
      ab->next=NULL;
      tail=ab;


  }
  /*
  void swap(int pos1,int pos2){
    node *temp1=new node;
    node *temp2=new node;

  }
*/
  void insertendm2(int n)
{
    node *tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
 }
   };

int main()
{
   list abc;
   int n;
   cout<<"no of elements"<<endl;
   cin>>n;
   for (int i=0;i<n;i++){
        int m;
   cin>>m;
    abc.createnode(m);
   }
    abc.display();
    cout<<"what to insert at start and end";
    int l;
    cin>>l;
    abc.insertstart(l);
    abc.insertendm1(l);
    abc.display();
     cout<<"what to insert at  end again with diff method";
    int k;
    cin>>k;
    abc.insertendm2(k);
    abc.display();
    return 0;
}
