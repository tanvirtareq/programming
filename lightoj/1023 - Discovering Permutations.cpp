#include<bits/stdc++.h>

using namespace std;

map<int, int>mp;
int x, ar[27];
string st;

void rec(int pos, int n, int k )
{
    if(x>=k) return;
    if(pos>n)
    {
        cout<<st<<endl;
        x++;
    }

    for(int i=1;i<=n;i++)
    {
        if(mp[i]!=1)
        {
            mp[i]=1;
            char ch=i-1+'A';
            st.push_back(ch);
            rec(pos+1, n,k);
            if(x>=k) return;
            mp[i]=0;
            st.erase(st.begin()+st.size()-1);

        }

    }
    return ;

}


int main()
{
    int n, t, k;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        mp.clear();
        x=0;
        string st1;
        st=st1;
        cout<<"Case "<<i<<":"<<endl;
        rec(1, n, k);

    }


    return 0;
}
