#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define slots 100

struct job{
char jname;
int deadline;
int profit;
};

bool cmp(job a,job b){
return (a.profit>b.profit);
}
void jobseq(job ar[],int n){
bool slot[n];
int res[n];
int c=0;
for(int i=0;i<n;i++){
        slot[i]=false;
}
sort(ar,ar+n,cmp);
for(int i=0;i<n;i++){
int k=ar[i].deadline;
//while (k-1>=0){
   for (int j=min(n, ar[i].deadline)-1; j>=0; j--)
       {
    if(slot[j]==false){
       // cout<<ar[i].jname;
        res[j]=i;
        slot[j]==true;
       c++;
            break;
    }
    //else {k--;}
}

}
for(int i=0;i<c;i++){
    cout<<res[i]<<endl;
   }
}
int main()
{
   job s[5];
    s[0].jname='a';
    s[1].jname='b';
    s[2].jname='c';
    s[3].jname='d';
    s[4].jname='e';
s[0].deadline=2;
s[1].deadline=1;
s[2].deadline=2;
s[3].deadline=1;
s[4].deadline=3;
s[0].profit=100;
s[1].profit=19;
s[2].profit=27;
s[3].profit=25;
s[4].profit=15;

/*

   for(int i=0;i<5;i++){
    s[i].profit=10*i;
   }
  */
  jobseq(s,5);

}
