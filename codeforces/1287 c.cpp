#include<bits/stdc++.h>
#define ll long long


using namespace std;

int n, ar[200], dp[4][200][200][200];

int dpf(int pr, int id, int odd, int evn)
{
    if(odd<0 or evn<0) return INT_MAX-100;n
    if(id>n) return 0;

    if(pr!=0 and dp[pr][id][odd][evn]!=-1) return dp[pr][id][odd][evn];

    if(ar[id]!=0)
    {
        int p=0;
        if(pr!=0 and pr%2!=ar[id]%2) p++;
        return p+dpf(ar[id], id+1, odd, evn);
    }

    int p=0, q=0;
    if(pr!=0 and pr%2==0 ) p++;
    else if(pr!=0 and pr%2) q++;
     p+=dpf(1, id+1, odd-1, evn);
     q+=dpf(2, id+1, odd, evn-1);
    return dp[pr][id][odd][evn]=min(p, q);

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof dp);

    cin>>n;
    int evn=n/2;
    int od=0;
    od=evn;
    if(n%2) od++;
    for(int i=1;i<=n;i++){
        cin>>ar[i];

        if(ar[i]%2) ar[i]=1, od--;
        else if(ar[i]!=0) ar[i]=2, evn--;
    }
//    od=evn=INT_MAX;

    cout<<dpf(0, 1, od, evn)<<endl;

    return 0;
}


