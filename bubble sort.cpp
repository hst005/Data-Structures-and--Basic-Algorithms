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
    for(int i=0;i<k-1;i++){
        for(int j=i+1;j<k;j++){
         if(a[i]>a[j]){
           /*
            int temp;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            */
            swap(&a[i],&a[j]);
         }
        }

    }
    for(int i=0;i<k;i++){
        cout<<a[i]<<endl;
    }

    return 0;
}
