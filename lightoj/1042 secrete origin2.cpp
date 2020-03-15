#include<bits/stdc++.h>

using namespace std;

int find_(int ch, int n)
{
    int c=0;
    int pos=0;
    for(int i=1;i<=32;)
    {
        pos++;
        if(n&i)
        {
            c++;
            if(c==ch)
            {
                cout<<"pos"<<pos<<endl;
                return pos;
            }
        }
        i=i<<1;
    }
}

int answ(int n)
{
    for(int i=1;i<=32;i++)
    {
        int x=find_(i, n);
        /// if n(x+1) is 0,
        if((n&(1<<x)==0))
        {
            if(n&(1<<x)) cout<<"1"<<endl;
            if(!n&(1<<x)) cout<<"0"<<endl;
            ///exchange
            n=n|(1<<x);
            cout<<n<<endl;
            int mask=0|(1<<(x-1));
            mask=~mask;
            n=n&mask;
            cout<<n<<endl;
            break;
        }
        else if(x==1) continue;
        else if(x==2&&(n&1)==0)
        {
            ///exchange with (x-1)
            int mask=1<<1;
            cout<<mask<<endl;
            mask=~mask;
            n=n|1;
            n=n&mask;


        }
        else if(!(n&(1<<(x-2))))
        {
            n=n|(1<<(x-2));

            int mask=0|(1<<(x-1));
            mask=~mask;
            n=n&mask;
        }
    }
    return n;

}

int main()
{

    int t;

//    cout<<t;

//    cout<<popcount(536870912)<<endl;

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        unsigned long long n, b1n, ans;
        cin>>n;

        ans=answ(n);

        cout<<"Case "<<i<<": "<<ans<<endl;

    }

    return 0;
}
