#include<bits/stdc++.h>
#define sz 1000000
#define psz 10000
typedef long long int lld;
using namespace std;
bool chk[sz+1];
vector<int>v;

void seive()
{
    int j=0;
    chk[2];
    for(int i=3;i*i<=sz;i++)
    {
        if(chk[i]==0)
        {
//            cout<<p[j-1]<<endl;
            for(int j=i*i;j<=sz;j=j+2*i)
            {
                chk[j]=1;
            }
        }
    }
    for(int i=2;i<=sz;i++)
        if(chk[i]==0)
    {
        v.push_back(i);
    }
//    cout<<j<<endl;
//    cout<<"ss"<<endl;
    return;

}

int main()
{
    seive();
    int t;
    long long int n;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld", &n);
        int cnt=0;
        long long int  ans=1;
//        cout<<(lld)v[v.size()-1]*v[v.size()-1]<<endl;
        for(int j=0;(lld)v[j]*v[j]<=n;j++)
        {
//            cout<<v[j]*v[j]<<endl;
//            cout<<p[j]<<endl;
            cnt=1;
            while(n%v[j]==0)
            {
                cnt++;
                n=n/v[j];
//                cout<<n<<endl;
            }
            ans=ans*cnt;

        }
        if(n>1) ans=ans*2;

        printf("Case %d: %lld\n", i, ans-1);
    }
    return 0;
}
