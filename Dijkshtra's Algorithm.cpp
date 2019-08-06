#include <iostream>

using namespace std;

int findminvert(int **grap,int *dist,bool *visited,int n){
    int minvert=-1;
    for(int i=0;i<n;i++){
            if(!visited[i] && (minvert==-1 || dist[i]<dist[minvert]) ){
                    minvert=i;
               }
    }
    return minvert;
}
void dijkshtra(int **grap,int n){

    int *dist=new int[n];
    bool *v=new bool[n];

    for(int i=0;i<n;i++){
        v[i]=false;
        dist[i]=INT_MAX;
    }
    dist[0]=0;      //considering 0 is source
    int count=1;
    int cv;       //current vertex
    for(int i=0;i<n-1;i++){
            cv=findminvert(grap,dist,v,n);
            v[cv]=true;
            count++;
            for(int i=0;i<n;i++){

                if(!v[i] && grap[cv][i]!=0){
                    if(dist[i]>dist[cv]+grap[cv][i]){
                        dist[i]=dist[cv]+grap[cv][i];
                    }
                }

            }


    }





    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
    delete [] v;
    delete [] dist;
}

int main()
{
    int v,e;
    cin>>v>>e;
    int **grap=new int*[v];
    for(int i=0;i<v;i++){
        grap[i]=new int[v];
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            grap[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        grap[a][b]=c;
        grap[b][a]=c;
    }
    dijkshtra(grap,v);
}
