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
    int t, n;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        cin>>n;

        cout<<"Case "<<i<<":"<<endl;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<2*n;j++)
            {
                if(i==1 and j==n) cout<<"*";
                else if(i==n and (j==1 or j==2*n-1)) cout<<"*";

                else if(i==n or j==n) cout<<"#";

                else if(j==n-i+1 or j==n+i-1) cout<<"*";

                else if(j>n+i-1) continue;


                else cout<<" ";



            }
            cout<<endl;

        }

        for(int i=n-1;i>0;i--)
        {
            for(int j=1;j<2*n;j++)
            {
                if(i==1 and j==n) cout<<"*";

                else if(j==n) cout<<"#";

                else if(j==n-i+1 or j==n+i-1) cout<<"*";

                else if(j>n+i-1) continue;

                else cout<<" ";

            }

            cout<<endl;

        }


    }

	return 0;
}


