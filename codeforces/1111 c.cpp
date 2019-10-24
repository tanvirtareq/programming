#include<bits/stdc++.h>
//#define m 10000007

typedef unsigned long long ull;
typedef long long int li;
//typedef vector<li> vli;


using namespace std;

li inline power(li b, li p)
{
    if(p==1) return b;
    if(p==0) return 1;

    li x=power(b, p/2);

    cout<<x<<endl;

    if(p%2==0)
    {
        return x*x;
    }
    else  x*x*b;

}


int main() {

    cout<<power((li)2, (li)3)<<endl;


    map<int, int> mp;
    map<int, int>:: iterator it;

    li n, k, a, b;
    cin>>n>>k>>a>>b;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;

        mp[x]++;
    }


    return 0;
}

/**

5 4 4
1 1 1 1 1

5 4 4
1 1 1 1 5

*/




