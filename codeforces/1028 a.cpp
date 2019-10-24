#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n, m, bn, bc, r, c;
    int bsx=-1;
    pair <int, int>st, en;

    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        char ch;
        cin>>ch;
        if(ch=='B')
        {
            if(bsx==-1)
            {
                st.first=i;
                st.second=j;
                bsx=0;
            }
            en.first=i;
            en.second=j;
        }
    }
//    cout<<st.first<<" "<<st.second<<endl;
    cout<<(st.first+en.first)/2<<" "<<(st.second+en.second)/2<<endl;



    return 0;
}
