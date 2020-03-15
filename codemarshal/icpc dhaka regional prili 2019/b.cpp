// Author : Tamzid Hossain
// Shahjalal University Of Science And Technology,Sylhet
// Bangladesh
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
//#include <bits/stdc++.h>
  
using namespace std;
  
#define ll              long long int
#define ui              unsigned int
#define ull             unsigned long long
#define PI              2*acos(0.0)
#define Mk              make_pair
#define Pb              push_back
#define ppb             pop_back
#define pshf            push_front
#define ppf             pop_front 
#define sp              " "
#define fst first
#define snd             second
#define FAST            ios_base::sync_with_stdio(false)
#define Dbug            cout<<"OK"<<endl
#define sf              scanf
#define pf              printf
#define clr( a, b )     memset((a),b,sizeof(a))
#define pii             pair<int, int>
#define pll             pair<long long int, long long int>
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
#define wait            system("pause")
#define ps              pf("PASS\n")
#define INF             1000000009
  
#define frn(i, n) for(int i = 0; i < n; i++)
#define frI(i,a,b) for(int i = (a); i <= (b); i++)
#define frD(i,a,b) for(int i = (a); i >= (b); i--)
int tc;
  
const int mod = 1000000007;
ll parent[100005];
multiset<int>arr[100005];
 
ll find(ll i) 
{ 
    if (parent[i] == i) 
        return i; 
    return parent[i] = find( parent[i]); 
} 
    
// Naive implementation of union() 
void Union(ll x, ll y) 
{ 
    ll xset = find( x); 
    ll yset = find( y);
 
    if(arr[xset].size() > arr[yset].size())
    {
        multiset<int>::iterator it = arr[yset].begin();
        for( ; it != arr[yset].end() ; it++)
            arr[xset].insert(*it);
        parent[yset] = xset;
    }
    else
    {
        multiset<int>::iterator it = arr[xset].begin();
        for( ; it != arr[xset].end() ; it++)
            arr[yset].insert(*it);
        parent[xset] = yset;
    }
  
} 
  
int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n,q;
    ll tc;
    sf("%lld",&tc);
    Dbug;
    for(ll i=1 ; i<=tc ; i++)
    {
        sf("%lld %lld",&n,&q);
        for(int j=0 ; j<=n ; j++)
            parent[j] = j;
 
        pf("Case %lld:\n",i);
        while(q--)
        {
            ll a,b,c,d;
            sf("%lld",&a);
            if(a==0)
            {
                sf("%lld %lld",&b,&c);
                Union(c,b);
 
            }
            else if(a==1){
                sf("%lld %lld",&b,&c);
                ll x = find(b);
                arr[x].insert(c);
            }
            else
            {
                sf("%lld %lld %lld",&b,&c,&d);
                ll x = find(b);
                // multiset<int>::iterator low,high;
                int low = (int)(lower_bound(arr[x].begin(),arr[x].end(),c)-arr[x].begin());
                int high = upper_bound(arr[x].begin(),arr[x].end(),d)-arr[x].begin();
                //int ans = (int)(high-low);
                int ans = abs(high-low);
                pf("%d\n",ans);
 
            }
        }
    }
     
 
    return 0;
}