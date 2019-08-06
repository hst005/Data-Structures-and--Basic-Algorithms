#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void findzeroneigh(int *ined,queue <int> *temp,int n,bool *visit){
    for(int i=0;i<n;i++){
        if (ined[i]==0 && visit[i]==false){
            temp->push(i);

        visit[i]=true;
        }
    }
}
void topsort(vector <int> *gr,int n,int *ined){
    queue <int> *temp=new queue <int>();
        bool visit[n];
    for(int i=0;i<n;i++){
        visit[i]=false;
    }
    findzeroneigh(ined,temp,n,visit);

    while(!temp->empty()){
        int curr=temp->front();
        temp->pop();
        cout<<curr<<endl;
        for(int i=0;i<gr[curr].size();i++){
            ined[gr[curr][i]]--;
        }
        findzeroneigh(ined,temp,n,visit);
    }



}
int main()
{
    int n;
    cin>>n;
    vector <int> gr[n];
    int e;
    cin>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
    }
    int *ined=new int[n];
    for(int i=0;i<n;i++){
        ined[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<gr[i].size();j++){
            ined[gr[i][j]]++;
        }
    }
    /*for(int i=0;i<n;i++){
        cout<<ined[i]<<endl;
    }*/
    topsort(gr,n,ined);
    return 0;
}
