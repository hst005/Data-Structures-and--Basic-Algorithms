#include <iostream>

using namespace std;
void swap(int *a,int *b){
int temp;
temp=*a;
*a=*b;
*b=temp;
}

int main()
{

    int k;
    cin>>k;
    int a[k];
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    int minm,pos;
    for(int i=0;i<k-1;i++){
            minm=a[i];
            pos=i;
        for(int j=i;j<k;j++){
            if(a[j]<minm){
                minm=a[j];
                pos=j;
            }
        }
        if(minm!=a[i]){
            swap(&a[i],&a[pos]);
        }
    }

    for(int i=0;i<k;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
