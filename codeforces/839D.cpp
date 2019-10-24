#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

#define m 1000000007
typedef long long int lld;
typedef unsigned long long ull;

using namespace std;



int n, ar[200010];

int dp(int state, int took, int gcd)
{
//    cout<<state<<" "<<took<<" "<<gcd<<endl;
    int q1=0, q2=0;
    if(state>n and (gcd==1 or gcd==-1))
    {
//        cout<<state<<" "<<n<<endl;
        return 0;
    }

    else if(state>n)
    {
        int x= ((took%m)*(gcd%m))%m;
        cout<<took<<"*"<<gcd<<endl;
        return x;
    }


    else if(gcd!=-1)
    {
        q1=dp(state+1, took+1, __gcd(gcd, ar[state]));
        q2=dp(state+1, took, gcd);
//        cout<<q1<<" "<<q2<<endl;

        return (q1%m+q2%m)%m;
    }
    else if(gcd==-1)
    {
//        cout<<"yes"<<endl;


        q1=dp(state+1, took+1, ar[state]);
        q2=dp(state+1, took, gcd);

//        cout<<q1<<" "<<q2<<endl;
        return (q1%m+q2%m)%m;
    }
}


int main()
{
//    int n;
    cin>>n;

    cin>>ar[1];

    for(int i=2;i<=n;i++)
    {
        cin>>ar[i];
    }

    cout<<dp(1, 0, -1)<<endl;

	return 0;
}
