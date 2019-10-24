#include<bits/stdc++.h>

using namespace std;

bool a[1000000];

void seive_prime()
{
    long long int i, j;
    a[1]=1;
    a[0]=1;

    for(i=2;i<=1000;i++)
    {
        for(j=i+i;j<=1000000;j=j+i)
        {
            a[j]=1;

        }


    }



}

int main()
{
    seive_prime();

    long long int n, x, sqrt;

    double dsqrt;

    cin>>n;

    while(n--)
    {
        cin>>x;

        dsqrt=pow(x, 0.5);


        if((dsqrt-floor(dsqrt))==0)
        {
            sqrt=(int)dsqrt;



            if(a[sqrt]==0)
                cout<<"YES"<<endl;

            else cout<<"NO"<<endl;

        }

        else cout<<"NO"<<endl;
    }

    return 0;
}
