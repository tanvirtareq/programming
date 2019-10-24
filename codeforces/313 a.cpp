#include<bits/stdc++.h>
#define sz 1000000
#define sq 1000
using namespace std;

bool a[sz+1];

void seive()
{
    for(int i=2;i<=sq;i++)
        if(a[i]==0)
        for(int j=i+i;j<=sz;j=j+i)
        a[j]=1;
    return;

}

int main()
{

    string st;
    cin>>st;

    if(st.size()==3&&(st[1]=='0'||st[2]=='0'))
    {
//        if(st[1]=='0'||st[2]=='0')
            cout<<"0"<<endl;
    }
    else {
    for(int i=0;i<st.size()-2;i++)
        cout<<st[i];
    if(st[0]=='-')
    {
        if(st[st.size()-1]>st[st.size()-2])
            cout<<st[st.size()-2];
        else cout<<st[st.size()-1];
    }
    else cout<<st[st.size()-2]<<st[st.size()-1]<<endl;
    }

    return 0;
}


