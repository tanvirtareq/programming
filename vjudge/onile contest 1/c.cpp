
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<utility>
#include<conio.h>
#include<algorithm>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;

bool cmp(pair<int, pair<int, int> > p, pair<int, pair<int, int> > q)
{
    if(p.second.first<q.second.first) return true;

    if(p.second.first==q.second.first and p.second.second<q.second.second) return true;

    return false;

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;

    cin>>t;
    while(t--)
    {
        cin>>n;

//        int m=n;
//        n=m*3;

        vector<pair<int, pair<int, int> > > v;

        for(int i=1;i<=3*n;i++)
        {
            int x, y;
            cin>>x>>y;

            v.push_back(make_pair(i, make_pair(x, y)));

        }

        sort(v.begin() , v.end(), cmp);

        for(int i=0;i<3*n;i+=3)
        {
            cout<<v[i].first<<" "<<v[i+1].first<<" "<<v[i+2].first<<endl;

        }

    }


	return 0;
}
