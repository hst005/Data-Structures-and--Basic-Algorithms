#include <iostream>

using namespace std;

struct node{
int data;
node *left;

node *right;
int height;
};


int getheight (node *a){
    if(a==NULL){
        return 0;
    }
    return a->height;
}

int balfact(node *a){
    if(a==NULL){
        return 0;
    }
    return getheight(a->left)-getheight(a->right);
}
/*
node *leftrotation(node *a){
    node *temp=a->left;
    a->left=temp->right;
    temp->right=a;

}*/
 node *rightRotate( node *y)
{
     node *x = y->left;
     node *T2 = x->right;


    x->right = y;
    y->left = T2;

    y->height = max(getheight(y->left), getheight(y->right))+1;
    x->height = max(getheight(x->left), getheight(x->right))+1;

    return x;
}


 node *leftRotate( node *x)
{
     node *y = x->right;
     node *T2 = y->left;


    y->left = x;
    x->right = T2;

    x->height = max(getheight(x->left), getheight(x->right))+1;
    y->height = max(getheight(y->left), getheight(y->right))+1;


    return y;
}

/*
node *rightrotation(node *a){

}*/

node *newnode(int val){
    node *temp=new node();
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    return temp;

}


node *insert(node *root,int val){
if(root==NULL){
    return(newnode(val));
}
if(root->data<val){
    root->left=insert(root->left,val);
}
else if(root->data<val){
    root->left=insert(root->left,val);
}
else{
    return root;
}

root->height=1+max(getheight(root->left),getheight(root->right));

int bal=balfact(root);

if(bal>1 && val>root->left->data){
    root->left=leftRotate(root->left);
    return rightRotate(root);

}

if(bal<-1 && val<root->left->data){
    root->right=rightRotate(root->right);
    return leftRotate(root);

}

if(bal>1 && val<root->left->data){

    return rightRotate(root);

}

if(bal<-1 && val>root->left->data){
    return leftRotate(root);

}
return root;
}

void preOrder(struct node *root)
{
    if(root != NULL)
    {
        cout<<(root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
     struct node *root = NULL;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */

  preOrder(root);return 0;
}
