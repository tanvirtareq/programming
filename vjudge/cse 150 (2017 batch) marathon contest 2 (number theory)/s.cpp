#include<bits/stdc++.h>
#define sz 10000000

using namespace std;

bool spf[sz+1];
int p[sz/2];

void find_spf()
{
    spf[1]=1;

    for(int i=2;i*i<=sz;i++)
    {
        if(spf[i]==0)
        {
            for(int j=i*i;j<=sz;j=j+i)
                if(spf[j]==0) spf[j]=1;
        }

    }

    for(int i=1, j=0;i<=sz;i++)
        if(spf[i]==0)
    {
        p[j]=i;
//        cout<<i<<endl;
        j++;
    }

    return;

}

int  posib(int n)
{
    int cnt=0;
    for(int i=0;p[i]*2<=n;i++)
    {
//        cout<<p[i]<<" "<<n-p[i]<<endl;
        if(spf[n-p[i]]==0)
        {

//            cout<<n<<" is the sum of "<<p[i]<<" and "<<n-p[i]<<"."<<endl;
            cnt++;
        }

    }
    return cnt;
}

int main()
{
    find_spf();

    int n, t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;

        cout<<"Case "<<i<<": "<<posib(n)<<endl;

    }

    return 0;
}


