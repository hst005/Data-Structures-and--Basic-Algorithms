#include <iostream>

using namespace std;

struct node{
int data;
node *left,*right,*parent;
bool col; // 0 red 1 black

node(int d,char c){
    data=d;
    left=NULL;
    right=NULL;
    parent=NULL;
    if(c=='R'){
        col=0;
    }
    else{
        col=1;
    }
}

};



/*
node *rightrotate(node *root){
    node *tx=root->left;
    root->left=tx->right;
    tx->right=root;

    return tx;
}

node *leftrotate(node *root){
    node *tx=root->right;
    root->right=tx->left;
    tx->left=root;

    return tx;
}
*/

class rbtree{
public:

    node *root;
    /*
void leftrotate(node *root,node *par){
    Node *pright = par->right;

    par->right = pright->left;

    if (par->right != NULL)
        par->right->parent = par;

    pright->parent = par->parent;

    if (par->parent == NULL)
        root = pright;

    else if (par == par->parent->left)
        par->parent->left = pright;

    else
        par->parent->right = pright;

    pright->left = par;
    par->parent = pright;

}

void rightrotate(node *root,node *pt){
     Node *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;

}
*/

void leftrotate(node *p)
{
     if(p->right==NULL)
           return ;
     else
     {
           node *y=p->right;
           if(y->left!=NULL)
           {
                  p->right=y->left;
                  y->left->parent=p;
           }
           else
                  p->right=NULL;
           if(p->parent!=NULL)
                y->parent=p->parent;
           if(p->parent==NULL)
                root=y;
           else
           {
               if(p==p->parent->left)
                       p->parent->left=y;
               else
                       p->parent->right=y;
           }
           y->left=p;
           p->parent=y;
     }
}

void rightrotate(node *p)
{
     if(p->left==NULL)
          return ;
     else
     {
         node *y=p->left;
         if(y->right!=NULL)
         {
                  p->left=y->right;
                  y->right->parent=p;
         }
         else
                 p->left=NULL;
         if(p->parent!=NULL)
                 y->parent=p->parent;
         if(p->parent==NULL)
               root=y;
         else
         {
             if(p==p->parent->left)
                   p->parent->left=y;
             else
                   p->parent->right=y;
         }
         y->right=p;
         p->parent=y;
     }
}

node *insert(node *root,int val){
    node *temp=new node(val,'R');
    node *par=root;
    node *q=NULL;
    if(root==NULL){
            root=temp;
    }
    else {
            while(par!=NULL){
                    q=par;
                if(par->data<val){
                    par=par->right;
                }
                else{
                    par=par->left;
                }
            }
                temp->parent=q;

            if(q->data<val){
                q->right=temp;
            }
            else{
                q->left=temp;
            }


    }
    insertfix(temp);
}

void insertfix(node *temp){
    node *u;
    if(root==temp){
        temp->col=1;
        return;
    }

    while(temp->parent!=NULL && temp->parent->col==0){
        node *grand=temp->parent->parent;
        /*if(temp->parent->col==0 && grand->right->col==0 ){


        }*/

        if(grand->left==temp->parent)
           {
                if(grand->right!=NULL)
                {
                        u=grand->right;
                        if(u->col==0)
                        {
                            temp->parent->col=1;
                            u->col=1;
                            grand->col=0;
                            temp=grand;
                        }
                }
                else
                {
                    if(temp->parent->right==temp)
                    {
                        temp=temp->parent;
                        leftrotate(temp);
                    }
                    temp->parent->col=1;
                    grand->col=0;
                    rightrotate(grand);
                }
           }
           else{
                if(grand->left!=NULL)
                {
                        u=grand->left;
                        if(u->col==0)
                        {
                            temp->parent->col=1;
                            u->col=1;
                            grand->col=0;
                            temp=grand;
                        }
                }
                else
                {
                    if(temp->parent->left==temp)
                    {
                        temp=temp->parent;
                        rightrotate(temp);
                    }
                    temp->parent->col=1;
                    grand->col=0;
                    leftrotate(grand);
                }
           }
       root->col=1;
    }
}

void preorder(node *root)
{

    if (root != NULL)
    {
       cout<< root->data<<" "<<root->col<<endl;

        preorder(root->left);
        preorder(root->right);
    }
}
};

int main()
{
    rbtree abc;
    abc.root=new node(5,1);
    abc.insert(abc.root,6);
    abc.insert(abc.root,3);
    abc.insert(abc.root,2);abc.insert(abc.root,61);
    abc.preorder(abc.root);

    return 0;
}
