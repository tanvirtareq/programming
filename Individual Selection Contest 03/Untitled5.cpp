#include<bits/stdc++.h>

using namespace std;

 class ConsecutiveOnes{
public:

    long long unsigned get(long long unsigned n, unsigned k)
    {
        long long unsigned f=1, ans;
        long long unsigned mask=(f<<k)-1;

        unsigned mx=mxconnumb(n);
//        cout<<mx<<endl;

        if(mx>=k) return n;
        else {

        ans=n|mask;
        while(ans<n)
        {
//            cout<<"mask"<<mask<<endl;
            mask=mask<<1;
            mask=mask|1;
            ans=n|mask;
        }
        ans=reduce(ans, k);
//        cout<<ans<<endl;
        return ans;
        }
    }

     unsigned mxconnumb(long long unsigned n)
    {
        unsigned mx=0;
        for(int i=1;i<=50;i++)
        {
            unsigned c=0;
            long long unsigned f=1;

            if(n&(f<<(i-1)))
            {
                c++;
                unsigned j;
                for(j=i;j<=50;j++)
                {
                    if(n&(f<<j))
                    {
                        c++;
                    }
                    else
                    {
                        if(mx<c) mx=c;
                        break;
                    }
                }
            }

        }
        return mx;

    }

    long long unsigned reduce(long long unsigned ans, unsigned k)
    {
        long long unsigned f=1;
        unsigned f1=cntf1(ans);
//        cout<<f1<<" f1"<<endl;
        unsigned rmndr=f1-k;
//        cout<<rmndr<<" remndr"<<endl;
        if(rmndr>0)
        {
            for(int i=1;i<=rmndr;i++)
            {
                if(ans&(f<<(i-1)))
                {
                    ans=ans^(f<<(i-1));
//                    cout<<ans<<endl;
                }
            }
        }
        return ans;

    }
    unsigned cntf1(long long unsigned ans)
    {
        unsigned cnt=0;
        long long unsigned f=1;

        for(int i=0;i<=50;i++)
        {
            if(ans&(f<<i)) cnt++;
            else return cnt;
        }
        return cnt;

    }


};



int main()
{
    ConsecutiveOnes c;
    cout<<c.get(1, 1)<<endl;

    return 0;
}
/**

364269800189924
33

55 4
*/



