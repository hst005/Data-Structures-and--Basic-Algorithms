#include <iostream>
#include<stack>
using namespace std;

void display(stack <int> g){
stack <int> q=g;
while(!g.empty()){
    cout<<g.top()<<endl;
    g.pop();
}
}
int main()
{
    stack <int> pq;
    pq.push(5);
    pq.push(15);
    pq.push(25);
    pq.push(35);
    display(pq);
    cout<<pq.size()<<endl;
    cout<<pq.top()<<endl;
    return 0;
}
