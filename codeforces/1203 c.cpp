#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned

using namespace std;

int main()
{
    ll n;
    cin>>n;
    ll gcd;
    cin>>gcd;
    n--;
    while(n--)
    {
        ll x;
        cin>>x;
        gcd=__gcd(gcd, x);
    }
//    cout<<gcd<<endl;

    ll ct=0;

    for(ll i=1;i*i<=gcd;i++)
    {
        if(i*i==gcd) ct++;
        else if(gcd%i==0) ct+=2;
    }
    cout<<ct<<endl;

    return 0;
}



