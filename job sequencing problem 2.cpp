#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct job{
char name;
int deadline,profit;
};/*
struct res{
char name;
bool emp;
};
*/
bool cmp(job a,job b){
return a.profit>b.profit;
}
void jobseq(job ar[],int n){
sort(ar,ar+n,cmp);
char res[n];
bool slot[n];
//res[ar[0].deadline-1].emp=false;
//res[ar[0].deadline-1].name=ar[0].name;
    for(int i=0;i<n;i++){
                slot[i]=true;
    }
    slot[ar[0].deadline-1]=false;
    res[ar[0].deadline-1]=ar[0].name;
    //int k;
    for(int i=1;i<n;i++){
        for(int j=min(n,ar[i].deadline)-1;j>=0;j--){
            if(slot[j]==true){
                slot[j]=false;
                res[j]=ar[i].name;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(slot[i]==false){
                cout<<res[i];
           }
    }
}

int main()
{
    job a[5];
    for(int i=0;i<5;i++){
        a[i].name=(char)(65+i);
    }
    a[0].deadline=2;
    a[1].deadline=1;
    a[2].deadline=2;
    a[3].deadline=1;
    a[4].deadline=3;

    a[0].profit=100;
    a[1].profit=19;
    a[2].profit=27;
    a[3].profit=25;
    a[4].profit=15;

    jobseq(a,5);
    return 0;
}
