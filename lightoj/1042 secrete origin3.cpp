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

int swp(int n,int i,int j)
{
    n=n^(1<<i-1);
    n=n^(1<<j-1);
    cout<<"swapd value "<<n<<endl;
    return n;

}

int answ(int n)
{

    int c=0;
    cout<<"checker is "<<c<<endl;
    for(int i=1, j=2;i<=32, j<=32;i++, j++)
    {
        cout<<"for i and j "<<i<<" "<<j<<endl;
        if(n&(1<<(i-1))&&(!(n&(1<<(j-1)))))
        {
            cout<<" iTh bit is 1 and j th bit is 0"<<endl;
            n=swp(n, i, j);
            cout<<n<<endl;
            return n;
        }
        else if(!(n&(1<<(i-1)))&&(n&(1<<(j-1))))
        {
            if(c==0)
            {


            cout<<"i th bit is 0 and j th bit is 1"<<endl;
            n=swp(n, i, j);
            c=1;
            cout<<"checker is "<<c<<endl;
            }
        }
    }
    return n;

}

int main()
{
//    int n, i, j;
//    while(cin>>n>>i>>j)
//    {
//        cout<<swp(n, i, j)<<endl;
//    }

    int t;

//    cout<<t;

//    cout<<popcount(536870912)<<endl;

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n, b1n, ans;
        cin>>n;

        ans=answ(n);

        cout<<"Case "<<i<<": "<<ans<<endl;

    }

    return 0;
}

