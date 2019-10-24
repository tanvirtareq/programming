#include<bits/stdc++.h>
#define sz 1000000

#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
//#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

bool chk[sz+10];

v(li) p;


void seive()
{
    p.push_back(2);
    for(li i=3;i<=sz;i+=2)
    {
        if(chk[i]==0){

                p.push_back(i);

        for(li j=i*i;j<=sz;j+=i)
        {
            chk[j]=1;
        }

        }

    }

}

bool prmchk(li x)
{
    if(x==2) return 1;

    else if(x%2==0) return 0;

    if(chk[x]==0) return 1;

    return 0;
}


li inline fuc(li x, li n)
{
    li s=0;

    while(n/x)
    {
        s+=n/x;
//        cout<<x<<n<<endl;
        n=n/x;
    }

    return s;
}


int main()
{
    seive();

//    cout<<p[5]<<endl;

    li n,  b;

    li s=1000000000000;

    cin>>n>>b;

    bool flg=0;

    for(li i=0;;i++)
    {
        if(p[i]*p[i]>b) break;

        else if(b%p[i]==0)
        {
            s=min(s, fuc(p[i], n));

            cout<<s<<endl;
            flg=1;
        }
    }

    if(flg==0) s=fuc(b, n);

    cout<<s<<endl;

	return 0;
}


