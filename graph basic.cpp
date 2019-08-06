#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void addedge(vector <int> g[],int a,int b){
g[a].push_back(b);
g[b].push_back(a);

}

//tis fn frm gfg
void printGraph(vector<int> adj[], int V){
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (int x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

int main()
{
    int v;
    cout<<"enter no of vertices";
    cin>>v;
    vector <int> g[v];
    int c=1;
    while(c!=0){
        int v1,v2,f;
        cin>>v1>>v2>>f;
        c=f;
        addedge(g,v1,v2);
    }
    printGraph(g,v);
    return 0;
}
