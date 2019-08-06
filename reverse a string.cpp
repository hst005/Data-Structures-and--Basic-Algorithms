#include <iostream>

using namespace std;

void rev(string s){
string t=NULL;
//t=s;
//int j;
for(int i=0;i<s.length();i++){
    int d;
    d=int(s[i]);
    if((d<=122 && d>=97) || (d<=90 && d>=65)){
       t=t+s[i];
       }
}
int j=s.length()-1;
int k=0;
for(int i=j;i>=0;i--){
    int d;
    d=int(s[i]);
    if((d<=122 && d>=97) || (d<=90 && d>=65)){
       s[i]=t[j-k];
       k++;
       }

}
}
int main()
{
    string s;
    cin>>s;
    rev(s);
    cout<<s;
    //cout << "Hello world!" << endl;
    return 0;
}
