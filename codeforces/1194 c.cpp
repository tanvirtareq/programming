#include<bits/stdc++.h>
#define f(n) for(int i=1;i<=n;i++)
#define fr(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a)
#define clrar(a) memset(a, 0, sizeof a)


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin>>q;

    while(q--)
    {
        string s, t, p;
        cin>>s>>t>>p;


        int i=0, j=0;

        int flag=0;


        while(j<t.size())
        {
            if(i<s.size() && s[i]==t[j])
            {
                i++, j++;
            }
            else
            {
                auto it=find(p.begin(), p.end(), t[j]);
                if(it==p.end())
                {
                    flag=1;
                    break;
                }
                p.erase(it);

                j++;
            }

        }

        (flag || (s.size()>t.size())|| (i!=s.size())) ? cout<<"NO"<<endl: cout<<"YES"<<endl;
    }

    return 0;
}


