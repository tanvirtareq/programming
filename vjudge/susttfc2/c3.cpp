#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

template<class T>
void inline showbinaryrepresentation_of_pos_int(T a)
{
    T x=log(a)/log(2)+1;

//    cout<<a<<endl;

    for(int i=x;i>=0;i--)
    {
        if(a&((T)1<<i))
        cout<<1;
        else cout<<0;

    }
    cout<<endl;

    return;

}

li inline power(li b, li p)
{
    if(b==2) return (li)1<<(p);

    if(p==0) return 1;

    if(p==1) return b;

    li x=power(b, p/2);

    if(p&1)
    {
        return b*x*x;
    }

    else return x*x;

}


/// for seive prime

#define sz 5000

bool chk[sz+5];
vector<lu> prime;

void seive()
{
    prime.push_back(2);

    for(lu i=3;i*i<=sz;i+=2)
    {
        if(chk[i]==0) {

        for(lu j=i+i;j<=sz;j+=i)
            chk[j]=1;

        }
    }


    for(lu i=3;i<=sz;i+=2)
    {
        if(chk[i]==0){
            prime.push_back(i);
        }
    }

   // cout<< prime[0] <<endl;


}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    seive();

    lu n, k;

    while(cin>>n>>k)
    {
        li s=1;

        map<lu, lu> mp, mp1;

        for(lu j=1;j<=k;j++)
        {
            lu x=n-j+1;

            for(int i=0;prime[i]<=x;i++)
            {
                while(x%prime[i]==0)
                {
                    mp[i]++;
//                    cout<<x<<endl;

                    x/=prime[i];
                }
            }

//            cout<<j<<endl;

            lu fc=j;

            for(int i=0;prime[i]<=fc;i++)
            {
                while(fc%prime[i]==0)
                {
                    mp1[i]++;
                    fc/=prime[i];
                }
            }

        }

//        cout<<"r"<<endl;

        lu ans=1;

        map<lu, lu> :: iterator it;

        for(it=mp.begin();it!=mp.end();it++)
        {
            int x=it->first;

            if(mp[x]>mp1[x])
            {
//                cout<<mp[x]<<endl;

                ans*=(mp[x]-mp1[x]+1);

//                cout<<ans<<endl;
            }

        }

//        if(s>1) ans*=2;

        cout<<ans<<endl;

    }



	return 0;
}


