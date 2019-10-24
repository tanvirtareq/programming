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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    li t;

    cin>>t;
    while(t--)
    {
        int n, m;

        cin>>n>>m;

        if(m<n) cout<<m<<endl;

        else
        {
            int limit=3+(n-3)*2;
            if(m>=limit) cout<<0<<endl;

            else
            {
                int dif=limit-m;
                cout<<dif<<endl;
            }

        }
    }


	return 0;
}
