#include<bits/stdc++.h>

using namespace std;

bool divis(string st, long long int m)
{
    long long int ans=0, p=1;
    reverse(st.begin(), st.end());
    long long int l=st.size();
//    cout<<st[l-1]<<endl;
    if(st[l-1]=='-')
    {
        st.erase(st.end()-1);
        l=st.size();
//        cout<<l<<endl;
    }

    for(long long int i=0;i<l;i++)
    {
        ans=(ans+p*(st[i]-'0'))%m;
        p=(10*p)%m;
    }

    return ans;


}

int main()
{
//    divis("-1000", 3);
    long long int t;
    cin>>t;
    for(long long int i=1;i<=t;i++)
    {
        string st;
        long long int m;
        cin>>st>>m;
        if(!divis(st, m)) cout<<"Case "<<i<<": divisible"<<endl;
        else cout<<"Case "<<i<<": not divisible"<<endl;

    }

    return 0;
}
