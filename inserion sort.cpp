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
     int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
/*
    for(int i=0;i<k;i++){
        for(int j=i;j>0;j--){
               // if(j>0){
            if(a[j]<a[j-1] ){
                swap(&a[j-1],&a[j]);
                break;
            }
                //}
        }
    }
*/int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
