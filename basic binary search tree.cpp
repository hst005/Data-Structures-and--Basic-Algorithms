#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
node *left;
node *right;

};

class bst{

public:
/*
node *root;
bst() {
root=NULL;
}
*/
node *create(int val){
node *temp=new node;
temp->data=val;
temp->left=NULL;
temp->right=NULL;
return temp;
}

//node *getroot(){
//return root;
//}

node *insert(node *root,int val){
node *temp=create(val);
//cout<<temp->data<<endl;
//temp=create(val);
if(root==NULL){
    root=temp;
return temp;
}
else if(root->data>val){
root->left=insert(root->left,val);
}
else if(root->data<val){
root->right=insert(root->right,val);
}
return root;
}
/*
bool search(node *root,int val){
if(root==NULL)
return false;
else if(root->data==val)
return true;
else if(root->data<val){
return  search(root->left,val);
}
else if(root->data>val){
 return search(root->right,val);
}
}
*/
node* search(node* root, int val)
{
    if (root == NULL || root->data == val)
       return root;
    if (root->data < val)
       return search(root->right, val);
 return search(root->left, val);
}
/*
void inorder(node *root){
if(root->left!=NULL){
inorder(root->left);}
cout<<root->data;
if(root->right!=NULL){
inorder(root->left);}
}
*/
void inorder(node *root)
{
	//cout<<"das"<<endl;
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
	/*
	else {
		//cout<<"ajuhsj";
	}

*/
}

int findmin(node *root){
node *temp=root;
while (temp->left!=NULL){
    temp=temp->left;
}
return temp->data;
}

node *mini(node *root){
node *temp=root;
while (temp->left!=NULL){
    temp=temp->left;
}
return temp;
}

int findmax(node *root){
node *temp=root;
while (temp->right!=NULL){
    temp=temp->right;
}
return temp->data;
}

node *del(node *root,int val){

    //node *temp=search(root,val);
    if(root==NULL){return root;}
    else if(root->data<val){ root->right=del(root->right,val);}
    else if(root->data>val){ root->left=del(root->left,val);}
    else{
    if (root->left==NULL && root->left==NULL){
        delete root;
        root=NULL;
        return root;
    }
    else if(root->left==NULL){
        node *temp2=root;
        root=root->right;
        delete temp2;
        return root;
    }
    else if(root->right==NULL){
        node *temp2=root;
        root=root->left;
        delete temp2;
        return root;
    }
    else {
        //int minright=findmin(root->right);
        node *temp=mini(root->right);
        root->data=temp->data;
        root->right=del(root->right,temp->data);
    }

    }

}


int findhgt(node *root){
if(root==NULL)
    return -1;
    /*yeh bhi sahi hai
int lefthgt=findhgt(root->left);

int righthgt=findhgt(root->right);
int n=max(lefthgt,righthgt)+1;
return n;
*/
return max(findhgt(root->right),findhgt(root->left))+1;
}
};



int main(){

bst a;
/*
a.insert(a.getroot(),15);
a.insert(a.getroot(),5);
a.insert(a.getroot(),21);
a.insert(a.getroot(),18);
a.insert(a.getroot(),1);
a.inorder(a.getroot());
*/
node *root = NULL;
    root = a.insert(root, 15);
    a.insert(root, 5);
    a.insert(root, 21);
    a.insert(root, 18);
    a.insert(root, 1);
    a.insert(root, 45);
    a.insert(root, 2);

    bool av,b;
    a.inorder(root);
cout<<"min is"<<a.findmin(root)<<endl;

    a.del(root,21);
    a.inorder(root);
    cout<<"next try"<<endl;
     a.del(root,1);
    a.inorder(root);

    cout<<"next try"<<endl;
     a.del(root,18);
    a.inorder(root);

    cout<<"next try"<<endl;
     a.del(root,11);
    a.inorder(root);
    cout<<"next try"<<endl;

    a.del(root,5);a.del(root,45);
a.inorder(root);
cout<<"back to orig"<<endl;
a.insert(root, 5);
    a.insert(root, 21);
    a.insert(root, 18);
    a.insert(root, 1);
    a.insert(root, 45);
    a.insert(root, 2);
    a.inorder(root);
/*
    av=a.search(root,5);
    b=a.search(root,99);
    cout<<av<<endl<<b;
*/
cout<<a.findhgt(root);
return 0;
}
