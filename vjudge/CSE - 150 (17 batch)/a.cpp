#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
typedef long long int lld;
typedef unsigned long long ull;

using namespace std;

lld ar[25];
lld tab[25][10010];
lld n;

lld dp(lld state, lld k, lld an)
{
//    cout<<state<<" "<<an<<" "<<k<<endl;

//    cout<<" an "<<an<<endl;

    if(k>0 and state>n) return 0;

    if(k<=0) return an;

    if(state>n) return an;


//    cout<<tab[state][k]<<endl;

//    if(tab[state][an]!=-1)
//    {
////            cout<<tab[state][k]<<endl;
//
//        return tab[state][an];
//    }

    lld q1=0, q2=0;

    q2=dp(state+1, k, an);
    q1=dp(state+1, k-1, an^ar[state] );

//    cout<<max(q1, q2)<<endl;

    return tab[state][an]=max(q1, q2);

}

int main()
{
    lld t;

    cin>>t;

    while(t--)
    {
        lld k;

        cin>>n>>k;
        lld mx=0;

        memset(tab, -1, sizeof tab);

        for(lld i=1;i<=n;i++)
        {
            cin>>ar[i];
            mx=max(mx, ar[i]);
        }

//        if(k==1) cout<<mx<<endl;

//        else
        cout<<dp(1, k, 0)<<endl;


    }


	return 0;
}

/**

1

3 1

1
2
3







2





5


1


2


3


4


5





5 3


3


4


5


7


4

*/

