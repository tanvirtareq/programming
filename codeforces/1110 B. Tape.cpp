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
typedef priority_queue<li> mxpqli;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;


int main()
{

    li n, m, k;

    cin>>n>>m>>k;

    li b[n+10];

    cin>>b[1];

    priority_queue<pair< li, pair<li, li> > > pq;

    for(li i=2; i<=n;i++)
    {
        cin>>b[i];

        pq.push(make_pair(abs(b[i]-b[i-1]), make_pair(b[i-1], b[i])));
    }

    vector<li> v;
    v.push_back(b[1]);

    for(li i=1;i<k;i++)
    {
        li x=pq.top().second.first;
        li y=pq.top().second.second;

        pq.pop();

        v.push_back(x);
        v.push_back(y);

    }

    v.push_back(b[n]);

    sort(v.begin(), v.end());

    li ans =0;

    for(li i=0;i<v.size();i+=2)
    {
        ans+=v[i+1]-v[i]+1;

    }

    cout<<ans<<endl;


	return 0;
}

/**

4 100 2
20 30 75 80


*/


