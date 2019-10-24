#include<bits/stdc++.h>
#define sz 10000000
typedef long long unsigned llu;

using namespace std;

int c[sz+1];

int chk()
{
    c[1]=1;
    for(int i=2;i<=sz;i=i+2)
    {
        c[i]=1;

    }
    for(int i=3;i<=sz;i=i+3)
    {
        c[i]=1;
    }
    for(int i=5;i<=sz;i=i+5)
    {
        c[i]=1;
    }
    for(int i=2;i*i<=sz;i++)
    {
        if(c[i]==0)
        {
            for(int j=i;j<=sz;j=j+i)
            {
                c[j]=2;
            }
        }
    }
    int cnt=0;

    for(int i=1;i<=sz;i++)
    {

        if(c[i]!=2){
                cnt++;
        cout<<i<<"  "<<cnt<<"  "<<c[i]<<endl;
        }
        if(cnt==1500) return i;
    }

}

int main()
{
    cout<<"The 1500'th ugly number is "<<"11411"<<endl;

    return 0;
}


