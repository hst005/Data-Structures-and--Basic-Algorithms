#include <iostream>

using namespace std;
class p{
    public:
void swap(int *a,int *b){
int temp;
temp=*a;
*a=*b;
*b=temp;
}
void swap(int a,int b){
int temp;
temp=a;
a=b;
b=temp;
}

void partitionq(int *a,int start,int end){
int pivot=a[end];
int pindex=start;
for(int i=start;i<=end;i++){
    if(a[i]<=pivot){
        //swap(&a[i],&a[pindex]);
            int temp;
temp=a[i];
a[i]=a[pindex];
a[pindex]=temp;
        pindex++;
    }
}
//swap(a[end],a[pindex]);
}
};

int main()
{
    p ab;
    int a[]={7,2,1,6,8,5,3,4};;

    ab.partitionq(a,0,7);
    for(int i=0;i<8;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
