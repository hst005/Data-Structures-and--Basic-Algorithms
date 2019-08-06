#include <iostream>

using namespace std;
class m{
public:

   void merge(int *a,int start,int end,int mid){
    int i=start,j=mid+1,k=0;
    int temp[end-start+1];
        while(i<=mid && j<=end){
        if(a[i]<a[j]){
            temp[k]=a[i];
            i++;//k++;
        }
        else {
            temp[k]=a[j];
            j++;//k++;
        }
        k++;
    }
    while(i<=mid){temp[k]=a[i];
            i++;k++;}

    while(j<=end){temp[k]=a[j];
            j++;k++;}

            for(int i=start;i<=end;i++){
                a[i]=temp[i-start];
            }

    }

    void mergesort(int *a,int start,int end){
    //int len=sizeof(a)/sizeof(a[0]);
    if(start<end){
    int mid=(start+end)/2;

    mergesort(a,start,mid);
    mergesort(a,mid+1,end);
    merge(a,start,end,mid);
    }
    }

};
int main()
{
    m ab;
    int a[]={7,2,1,6,8,5,3,4};;
    //cout<<"length of ar is"<<sizeof(a)/sizeof(a[0])<<endl;
    ab.mergesort(a,0,7);
    for(int i=0;i<8;i++){
        cout<<a[i]<<endl;
    }
   // cout << "Hello world!" << endl;
    return 0;
}
