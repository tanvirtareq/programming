#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned

using namespace std;

int ar[6000000];
int mx=150001;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        ar[x]++;
    }

    for(int i=1;i<=mx;i++)
    {
        if(ar[i]>=2)
        {
            ar[i+1]++;
            ar[i]--;
        }
        else if(ar[i]==0 and ar[i+1]>=1)
        {
            ar[i]++;
            ar[i+1]--;
        }
    }

    int ct=0;

    for(int i=1;i<=mx;i++)
    {
        if(ar[i]>=1) ct++;
//        cout<<i<<" "<<ct<<endl;
    }

    cout<<ct<<endl;

    return 0;
}



