#include<bits/stdc++.h>
using namespace std;

int n,a[1000005],v[10000005];


int main()
{


    map<int,int>last;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
        v[i]=a[i];
        last[a[i]]=i;
    }

    sort(v,v+n);

    int st=-1,en=-1;

    for(int i=0;i<n;i++){
        if(a[i]!=v[i]){
            st=i+1,en=last[v[i]]+1;
            reverse(a+i,a+last[v[i]]+1);
            break;
        }
    }


    for(int i=0;i<n;i++){
        if(a[i]!=v[i]){
            cout<<"impossible\n";
            return 0;
        }
    }

    if(st==-1){
        st=1,en=1;
    }

    cout<<st<<' '<<en<<endl;



}
