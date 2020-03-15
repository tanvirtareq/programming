#include<bits/stdc++.h>
#define sz 1000000

using namespace std;

int spf[sz+1];
int p[sz];

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

    for(int i=2, j=0;i<=sz;i++)
        if(spf[i]==0)
    {
        p[j]=i;
//        cout<<i<<endl;
        j++;
    }

    return;

}

int main()
{
    find_spf();

    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int cnt=0;
        int x=n;
        for(int i=0;p[i]<=n;i++)
        if(n%p[i]==0){
            cnt++;
            n=n/p[i];
        }
        cout<<x<<" : "<<cnt<<endl;
    }

    return 0;
}
