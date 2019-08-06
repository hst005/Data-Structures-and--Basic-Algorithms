#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct act{
char name;
int start,fin;
};

bool cmp(act a,act b){
return (a.fin<b.fin);
}

int main()
{
    act a[6];
    for(int i=0;i<6;i++){
        a[i].name=(char)(65+i);
    }
    a[0].start=0;
    a[0].fin=6;
    a[1].start=3;
    a[1].fin=4;
    a[2].start=1;
    a[2].fin=2;
    a[3].start=5;
    a[3].fin=9;
    a[4].start=5;
    a[4].fin=7;
    a[5].start=8;
    a[5].fin=9;
    sort(a,a+6,cmp);

    int j=0;
    cout<<a[0].name<<"->";
    for(int i=1;i<6;i++){
        if(a[i].start>=a[j].fin){
            cout<<a[i].name<<"->";
            j++;
        }
    }
    return 0;
}
