#include<bits/stdc++.h>
#define sz 10000
using namespace std;

int spf[sz+1];

void find_spf()
{
    spf[1]=2;

    for(int i=2;i*2<=sz;i++)
    {
            for(int j=i+i;j<=sz;j=j+i)
                spf[j]++;

    }
    return;

}

int main()
{
    find_spf();

//    for(int i=1;i<=sz;i++)
//        cout<<spf[i]<<endl;
    int t, l, h;
    cin>>t;
    while(t--)
    {
        cin>>l>>h;
        int c=0;
        for(int i=l;i<=h;i++)
        {
            if(spf[spf[i]+2]==0)
            {
                if(c==1) cout<<" ";
//                cout<<spf[i]<<" "<<spf[spf[i]+2]<<endl;
                cout<<i;
                c=1;
            }
        }
        if(c==0) cout<<"-1"<<endl;
        else cout<<endl;

    }

    return 0;
}

