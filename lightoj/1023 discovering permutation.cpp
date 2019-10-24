#include<bits/stdc++.h>

using namespace std;

int main()
{

    int t, k, n;
//    cin>>t;
    t=100;
    for(int i=1;i<=t;i++)
    {
        string st;
//        cin>>n>>k;
        n=26;
        k=30;
        for(int j=0;j<n;j++)
        {
            st.push_back('A'+j);
        }
        string x=st;
        cout<<"Case "<<i<<":"<<endl;
        cout<<st<<endl;
        next_permutation(st.begin(), st.end());
        k--;
        k--;
        while(k--&&st!=x)
        {
             cout<<st<<endl;
            next_permutation(st.begin(), st.end());

        }
    }

    return 0;
}

