#include<bits/stdc++.h>
//#define sz 90000000
#define sz 2017333017

typedef long long int llu;

using namespace std;


llu chk[sz/64];
llu x;

vector<llu> p;

void prntbit(llu x)
{
    for(llu i=0;i<8*sizeof(x);i++)
    {
//        llu t=1<<i;
        llu t=1;
        if(x&t<<i) cout<<1;
        else cout<<0;

    }
//    cout<<endl;

}

void bitseiv()
{
    p.push_back(2);
    llu c=0;
    for(llu i=3;i<=sz;i+=2)
    {
//        prntbit(chk[i/64]);
        llu t=1;
        if((chk[i/64]&(t<<(i%64)))==0)
        {
//            cout<<"prm="<<i<<endl;
           p.push_back(i);

           for(long long unsigned j=(long long unsigned)i*i;j<=sz;j=j+2*i)
           {
//               prntbit(chk[j/64]);
//               cout<<j<<" ";
               llu t=1;

               chk[j/64]|=t<<(j%64);
//               prntbit(chk[j/64]);
           }
//           cout<<endl;
        }

    }
//    cout<<p.size()<<endl;
    return;
}

bool prchk(llu x)
{
    if(x==2) return 1;
    else if(x%2==0) return 0;
    llu t=1;
    if(chk[x/64]&t<<(x%64)) return 1;
    else return 0;

}

int main()
{


    bitseiv();
     if(prchk(2017331017)) cout<<"y"<<endl;
    int  t;
    llu x;
    cin>>t;
    while(t--)
    {
        cin>>x;
        cout<<p[x-1]<<endl;
    }
    return 0;
}

/**
7
1
10
100
1000
10000
100000
1000000
*/

