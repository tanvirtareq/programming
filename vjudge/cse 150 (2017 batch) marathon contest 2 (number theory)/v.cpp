#include<bits/stdc++.h>
#define sz 100000000

using namespace std;

int spf[sz+1];
int p[sz];
//vector<<int> p;
map<int, int>mp;

void find_spf()
{
    spf[1]=1;
    spf[0]=1;

    for(int i=3;i*i<=sz;i=i+2)
    {
        if(spf[i]==0)
        {
            for(int j=i*i;j<=sz;j=j+2*i)
                if(spf[j]==0) spf[j]=1;
        }

    }
//    p[0]=1;
//    mp[1]=0;

    p[1]=2;
    mp[2]=1;

    for(int i=3, j=2;i<=sz;i=i+2)
        if(spf[i]==0)
    {
        p[j]=i;
        mp[i]=j;
//        cout<<i<<endl;
        j++;

    }

    return;

}

bool isprm(int x)
{
    if(x==2) return 1;
    else if(x%2==0) return 0;
    else if(x<=1) return 0;

    else return !spf[x];
}

bool posib(int n)
{
    bool c=0;

    if(n<=4) {
//        cout<<n<<" is not the sum of two primes!"<<endl;
        printf("%d is the not sum of two primes!\n", n);
        return 0;
    }

    else if(n%2==1&&isprm(n-2))
    {
//         cout<<n<<" is the sum of "<<2<<" and "<<n-2<<"."<<endl;
            printf("%d is the sum of 2 and %d.\n", n, n-2);
         return 1;
    }
    else if(n%2==1)
    {
//        cout<<n<<" is not the sum of two primes!"<<endl;
        printf("%d is the not sum of two primes!\n", n);
        return 0;
    }


    int x, y, j=0;
    for(int i=ceil((float)n/2)-1;i>=0;i--)
    {
        if(isprm(i))
        {
//            cout<<"i  "<<i<<endl;
            j=mp[i];
//            cout<<j<<endl;
            break;
        }
    }

    for(int i=j;i>=0;i--)
    {
//        cout<<p[i]<<" "<<n-p[i]<<endl;
        if(2*p[i]!=n&&isprm(n-p[i]))
        {

            x=p[i];
            y=n-p[i];
            c= 1;
//            cout<<n<<" is the sum of "<<x<<" and "<<y<<"."<<endl;
             printf("%d is the sum of %d and %d.\n", n,x,y);
            return 1;
        }

    }
    if(c==0)
    {
        printf("%d is the not sum of two primes!\n", n);
//        cout<<n<<" is not the sum of two primes!"<<endl;
    }
    return 0;
}

int main()
{
    freopen("inp.txt","r", stdin);
    freopen("out.txt","w", stdout);

    find_spf();

//    map<int ,int> ::iterator it;
//    for(it=mp.begin();it!=mp.end();it++)
//    {
//        cout<<it->first<<"  "<<it->second<<endl;
//    }
////
//for(int i=1;i<=20;i++)
//    cout<<"("<<posib(i)<<")"<<endl;

    int n;
    while(scanf("%d", &n))
    {
////        if(n==4) cout<<"4 is the sum of 2 and 2."<<endl;
//        if(n%2!=0&&n>1)
//        {
////            cout<<" gh"<<endl;
//            if(spf[n-2]==0) cout<<n<<" is the sum of "<<2<<" and "<<n-2<<"."<<endl;
//            else cout<<n<<" is not the sum of two primes!"<<endl;
//        }
//
//        else if(!posib(n)) cout<<n<<" is not the sum of two primes!"<<endl;

        posib(n);

    }

    return 0;
}

