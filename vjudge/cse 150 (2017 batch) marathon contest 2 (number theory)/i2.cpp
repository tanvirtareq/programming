#include<bits/stdc++.h>

using namespace std;
    map<int , int > mp;

void fact(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            mp[i]++;
            n=n/i;
        }
    }
    return;

}

int power(int b, int p)
{
    if(p<=0) return 1;
    else if(p==1) return b;
    else if(p%2==0)
    {
        int x=power(b, p/2);
        return x*x;
    }
    else
    {
        int x=power(b, p/2);
        return b*x*x;
    }
}

int main()
{
    int n, k, x;
    cin>>n>>k;


    map<int , int>:: iterator it;

    fact(n) ;
    k--;
    int ans=1;
    cout<<mp.begin()->first<<endl;
    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
        if(it->second>k)
        {
            ans*=power(it->first, k);
//            break;
        }
        else if(it->second<=k)
        {
            ans*=power(it->first, it->second);
            k-=it->second;
        }
    }
    cout<<ans<<endl;




    return 0;
}
