
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int a, b, ct=0, divider, divisor;

    cin>>divisor>>divider;

    while(1)
    {
        ct=divisor/divider+ct;

        long long int temp=divider;
        divider=divisor%divider;



        divisor=temp;

        if(divider==0) break;



    }

    cout<<ct<<endl;


    return 0;
}


