#include<bits/stdc++.h>
#define sz 1000
using namespace std;

bool chk[sz+1];
int prime[sz];

void seive()
{
    chk[1]=1;

    for(int i=2;i*i<=sz;i++)
    {
        if(chk[i]==0)
        {
            for(int j=i*i;j<=sz;j=j+i)
                chk[j]=1;
        }

    }

    int x=0;
    for(int i=2;i<=sz;i++)
    {
        if(chk[i]==0)
        {

        prime[x]=i;
        x++;
        }
    }
    return;

}

bool isdiv(int a[], int x, int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]%x==0)
        {
            c++;
//            cout<<"divis "<<a[i]<<endl;
        }
        if(c==2) return 1;
    }
    return 0;

}

string multi(string st, int x)
{
    string ans;
    int c=0;
    for(int i=st.size()-1;i>=0;i--)
    {
        int anss=(st[i]-'0')*x+c;
        c=anss/10;
        ans.push_back((anss%10)+'0');
    }
    while(c!=0)
    {

        ans.push_back(c%10+'0');
        c=c/10;

    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main()
{

//    string xst;
//    int x;
//    while(cin>>xst>>x)
//    {
//        cout<<multi(xst, x)<<endl;
//    }

    seive();

    int t, n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        int a[n];
        int x=n;
        int mx=0;
        while(x--)
        {
            cin>>a[x];
            if(mx<a[x]) mx=a[x];
        }
//        cout<<"mx ="<<mx<<endl;
        string ans="1";
        for(int j=0;prime[j]<=mx;j++)
        {
//            cout<<prime[j]<<endl;
            if(isdiv(a, prime[j], n))
            {
//                cout<<"divisible "<<prime[j]<<endl;
                for(int k=0;k<n;k++)
                {
                    if(a[k]%prime[j]==0)
                        a[k]=a[k]/prime[j];
                }
                ans=multi(ans, prime[j]);
            }
        }
        for(int j=0;j<n;j++)
            ans=multi(ans, a[j]);

        cout<<"Case "<<i<<": "<<ans<<endl;
    }

    return 0;
}


