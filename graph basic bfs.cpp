#include <iostream>
#include<bits/stdc++.h>
using namespace std;


class graph{

int v;

list <int> *adj;
public:
    graph(int v){
        this->v=v;
        adj=new list<int> [v];
    }
   void addedge(int a,int b){
    adj[a].push_back(b);
   }

   void bfs(int s){

   bool visited[v];
   for(int i = 0; i < v; i++)
        visited[i] = false;

        list <int> queuee;

   visited[s]=true;
   queuee.push_back(s);

   list <int>::iterator i;

   while(!queuee.empty()){

        s=queuee.front();
        cout<<s;
   queuee.pop_front();

    for(i=adj[s].begin();i!=adj[s].end();i++){
        if(visited[*i]==false){
            queuee.push_back(*i);
            visited[*i]=true;
        }
    }
   }



   }
};
int main()
{
     graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.bfs(2);
    return 0;
}
