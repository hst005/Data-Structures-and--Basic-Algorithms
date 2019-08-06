#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void searchpat(string pat,string txt){
int n,m;
n=txt.length();
m=pat.length();
if(m>n){
    return ;
}
for(int i=0;i<=n-m;i++){
        int j;
    for( j=0;j<m;j++){
        if(txt[i+j]!=pat[j]){
            break;
        }
    }
    if(j==m){
        cout<<"found at"<<i<<endl;
    }
}

}
int main()
{
    string txt,pat;
    cout << "enter text" << endl;
    cin>>txt;
    cout << "pattern to search" << endl;
    cin>>pat;
    searchpat(pat,txt);
    return 0;
}
