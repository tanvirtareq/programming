#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

int main()
{
    stack<int>st, mx;
    int q, mnx=0;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int y;
            cin>>y;
            st.push(y);
            if(mx.empty()||y>=mx.top())
                mx.push(y);
        }
        else if(x==2)
        {
            int y=st.top();
            if(y==mx.top()) mx.pop();

            st.pop();
        }
        else if(x==3)
        {
            cout<<mx.top()<<endl;

        }

    }

    return 0;
}

