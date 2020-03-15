#include<bits/stdc++.h>
using namespace std;
int main(){
    string x, t;
    cin>>x>>t;
    int pr[x.size()+10], pst[x.size()+10], j=0, i=0;
    while(i<x.size() and j<t.size()){
        if(x[i]==t[j]) pr[j]=i, j++;
        i++;
    }
    j=t.size(), i=x.size();
    while(i>=0 and j>=0){
        if(x[i]==t[j]) pst[j]=i, j--;
        i--;
    }
    int mx=pst[0];
    for(int i=0;i<t.size()-1;i++)
        mx=max(mx, pst[i+1]-pr[i]-1);
    mx=max(mx, (int)x.size()-pr[t.size()-1]-1);
    cout<<mx<<endl;
    return 0;
}

