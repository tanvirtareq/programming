
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

int distsq(pair<int , int> a, pair<int, int> b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);

}

li mn[110], fv[110], n;

li tab[110][11000];

li dp(li s, li m)
{
    if(s>n) return 0;

    if(m<0) return 0;

    if(tab[s][m]!=-1) return tab[s][m];

    li p=dp(s+1, m);

    li q=0;
    if(m>=mn[s])
    q=dp(s+1, m-mn[s])+fv[s];

    return tab[s][m]=max(p, q);



}

li  m =1000003;


li rec(li *f, li *l, li *r, li g)
{

    string x;

    while(x!="[") cin>>x;

    while(x!="]")
    {
        if(x=="forward")
            {
                li n;
                cin>>n;
                *f=(*f%m+((n%m)*(g%m))%m)%m;

            }

            else if(x=="left")
            {
                li n;
                cin>>n;
                *l=(*l%m+((n%m)*(g%m))%m)%m;

            }

            else if(x=="right")
            {
                li n;
                cin>>n;
                *r=(*r%m+((n%m)*(g%m))%m)%m;

            }

            else if(x=="repeat")
            {
                li n;
                cin>>n;

                rec(f, l, r, ((n%m)*(g%m))%m);

            }

            cin>>x;


    }

    return 0;

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    li t;

    cin>>t;
    while(t--)
    {
        string x;

        cin>>x;

        while(x!="begin") cin>>x;

        li f=0, l=0, r=0;

        while(x!="end")
        {
            if(x=="forward")
            {
                li n;
                cin>>n;
                f=(f%m+n%m)%m;

            }

            else if(x=="left")
            {
                li n;
                cin>>n;
                l=(l%m+n%m)%m;

            }

            else if(x=="right")
            {
                li n;
                cin>>n;
                r=(r%m+n%m)%m;

            }

            else if(x=="repeat")
            {
                li n;
                cin>>n;

                rec(&f, &l, &r, n%m);

            }

            cin>>x;

        }

        cout<<l<<" "<<r<<" "<<f<<endl;

    }

	return 0;
}

/**

1900 3
2000 5
1950 2
101 1

*/




