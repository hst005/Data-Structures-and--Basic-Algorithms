#include<iostream>
using namespace std;

#define max 100

class stack{
int top;
int a[max];
public:
stack(){
top=0;
}

void swape(int a,int b){
int temp=a;
a=b;
b=temp;
}
/*
int *rev(int a[]){
int half;
if(top%2==0)
    {
        half=top/2;
        for(int i=0;i<half;i++){
               // cout<<"i is "<<stack[i]<<"  top-i is"<<stack[top-i]<<endl;
            swape(a[i],a[top-i]);
        //cout<<"i is "<<stack[i]<<"  top-i is"<<stack[top-i]<<endl;
        }
    }
return a;
}
*/
bool isempty(){
if(top==0)
return true;
return false;
}

bool isfull(){
if(top==max)
return true;
return false;
}

void push(int val){
if(top<max){
a[top++]=val;
}
}

void pop(){
cout<<a[--top]<<endl;
}

};

int main(){
stack abc;
abc.push(5);
abc.push(10);
abc.push(15);
abc.push(20);
//abc.pop();
//abc.pop();
//abc.pop();

abc.pop();
abc.pop();
abc.pop();
abc.pop();
return 0;
}
