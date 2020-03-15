#include<bits/stdc++.h>

#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cput<<#a<<" = "<<a<<endl

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    string x;
    cin>>x;
    int f=0;
    for(int i=1;i<x.size();i++)
    {
        if(x[i]==x[i-1]) f=1;
    }

    if(f) cout<<"Change needed"<<endl;
    else cout<<"No change needed"<<endl;

	return 0;
}


