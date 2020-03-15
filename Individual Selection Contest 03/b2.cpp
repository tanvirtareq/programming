#include<bits/stdc++.h>

using namespace std;

typedef long long unsigned lld;

lld con1(lld n, lld x)
{
    lld ans=0;

    while(x--)
    {
        if(n&(1<<x))
        {
            ans++;
            cout<<x<<" th bit is 1"<<endl;
        }
        else break;
    }
    return ans;

}

lld binary2dec(lld x, lld k)
{
    int ans=0;
    for(lld i=x;i>=k;i--)
    {
        ans=ans|(1<<(i-1));
    }
    return ans;

}

lld power(lld b, lld p)
{
    if(p==1) return b;
    else if(p%2==0){
        lld tmp=power(b, p/2);
//        cout<<tmp<<endl;
        return tmp*tmp;
    }
    else
    {
        lld tmp=power(b, (p-1)/2);
        return tmp*tmp*b;
    }
}

int main()
{
    lld n, m, k, ans, f=1;

    cin>>n>>k;


    lld x=floor((float)log(n)/log(2))+1;
    lld mask=(f<<k)-1;
//    cout<<mask<<endl;

    ans=n|mask;
    while(ans<n)
    {
        mask=mask<<1;
        ans=n|mask;
        cout<<ans<<endl;
    }

    cout<<ans<<endl;

    return 0;
}
/**

364269800189924
33
*/

