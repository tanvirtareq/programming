#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;


int n, e;
int clr[1100];
int clr1, clr0;


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {

        int n, m;
        vector<int> a, b;
        cin>>n;

        set<int> as, bs;

        while(n--)
        {
            int x;
            cin>>x;
            a.push_back(x);

        }

        cin>>m;
        while(m--)
        {
            int x;
            cin>>x;
            b.push_back(x);

        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for(int j=0;j<a.size();j++)
        {
            for(int k=0;k<b.size();k++)
            {
                if(b[k]%a[j]==0)
                {
                    as.insert(j);
                    bs.insert(k);
                }

            }

        }
        cout<<"Case "<<i<<": "<<min(as.size(), bs.size())<<endl;

    }

	return 0;
}

/**


*/



