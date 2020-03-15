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
    int ar[n+10], br[n+10];
    for(int i=1;i<=n;i++) cin>>ar[i];
    int ct=1;
    br[n]=0;
    for(int i=n-1;i>=1;i--)
    {
        if(ar[i]+1<ar[i+1])
        {
            ct++;
        }
        else
        {
            ct=1;
        }
        if(ct>1) br[i]=ct;
        else br[i]=0;
//        cout<<ct<<endl;
    }

    for(int i=1;i<=n;i++) cout<<br[i]<<endl;

	return 0;
}



