#include<bits/stdc++.h>
#define sz 100000000

using namespace std;

int spf[sz+1];
int p[sz];
map<int, int>mp;

void find_spf()
{
    spf[1]=1;
    spf[0]=1;

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
        mp[i]=j;
//        cout<<i<<endl;
        j++;

    }

    return;

}

bool posib(int n)
{
    bool c=0;
    int x, y, j=0;
    for(int i=ceil((float)n/2)-1;i>=0;i--)
    {
        if(spf[i]==0)
        {
//            cout<<"j  "<<i<<endl;
            j=mp[i];
//            cout<<j<<endl;
            break;
        }
    }

    for(int i=j;i>=1;i--)
    {
//        cout<<p[i]<<" "<<n-p[i]<<endl;
        if(2*p[i]!=n&&spf[n-p[i]]==0)
        {

            x=p[i];
            y=n-p[i];
            c= 1;
            cout<<n<<" is the sum of "<<x<<" and "<<y<<"."<<endl;
            return 1;
        }

    }
    return 0;
}

int main()
{
    find_spf();

    int n;
    while(cin>>n)
    {
//        if(n==4) cout<<"4 is the sum of 2 and 2."<<endl;
        if(n%2!=0&&n>1)
        {
//            cout<<" gh"<<endl;
            if(spf[n-2]==0) cout<<n<<" is the sum of "<<2<<" and "<<n-2<<"."<<endl;
            else cout<<n<<" is not the sum of two primes!"<<endl;
        }

        else if(!posib(n)) cout<<n<<" is not the sum of two primes!"<<endl;

    }

    return 0;
}

