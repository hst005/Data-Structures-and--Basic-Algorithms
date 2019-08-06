#include <iostream>

using namespace std;

struct node{
int data;
node *left,*right;

};

node *newnode(int k){
    node *temp=new node();
    temp->data=k;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

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


node *splay(node *root,int k){
    if(root==NULL || root->data == k){
        return root;
    }

    //root=splay(root,k);

    if(root->data>k){
        //left subtree
        if(root->left==NULL)
            return root;

        if(root->left->data>k){
            //zig zig
            root->left->left=splay(root->left->left,k);
            //root->left=rightrotate(root->left);
            root=rightrotate(root);
            //rotation grandparent ke through
        }
        else if(root->left->data<k){
            //zig zag
            root->left->right=splay(root->left->right,k);
            if (root->left->right != NULL)
                root->left = leftrotate(root->left);
        }
        return (root->left == NULL)? root: rightrotate(root);
        }

    else{
        //right sub

        if(root->right==NULL){
            return root;
        }

        if(root->right->data>k){
            //zig zag
            //thrugh parent
            root->right->left=splay(root->right->left,k);
            if (root->right->left != NULL){
                root->right = rightrotate(root->right);
            }
        }
        else if(root->right->data<k){
            //zig zig
            root->right->right=splay(root->right->left,k);
            //grandparent
            root=leftrotate(root);

        }
        return (root->right == NULL)? root: leftrotate(root);
    }

}

node *search( node *root, int key)
{
    return splay(root, key);
}

void preorder(node *root)
{
    if (root != NULL)
    {
       cout<< root->data;
        preorder(root->left);
        preorder(root->right);
    }
}
node *insert(node *root,int k){
    if(root==NULL)
        return root;
    root=splay(root,k);

    if(root->data==k)
        return root;
    node *newnod=newnode(k);
    if(root->data>k){
        newnod->right = root;
        newnod->left = root->left;
        root->left = NULL;
    }
      else
    {
        newnod->left = root;
        newnod->right = root->right;
        root->right = NULL;
    }
return newnod;
}

node *delval(node *root,int k){
    if(root==NULL)
        return root;
    node *temp=new node();
    root=splay(root,k);

    if(root->data!=k)
        return root;

    if(!root->left){
       // temp=root;
        //root=root->right;
        return root->right;
    }
    else{
        temp=root;
        root=splay(root->left,k);
        root->right=temp->right;
    }
   delete temp;
    return root;

}

int main()
{
   struct node *root = newnode(100);
    root->left = newnode(50);
    root->right = newnode(200);
    root->left->left = newnode(40);
    root->left->left->left = newnode(30);
    root->left->left->left->left = newnode(20);
    root = insert(root, 25);
    preorder(root);
    root = search(root, 25);
    cout<<endl;
   // cout<<"Preorder traversal of the modified Splay tree is \n";
    preorder(root);
       root = delval(root, 25);
    cout<<endl;
   // cout<<"Preorder traversal of the modified Splay tree is \n";
    preorder(root);
    /*
    struct node *root = newnode(6);
    root->left = newnode(1);
    root->right = newnode(9);
    root->left->right = newnode(4);
    root->left->right->left = newnode(2);
    root->right->left = newnode(7);

     int key = 4;
     root=delval(root,key);
     preorder(root);
    */return 0;

}
