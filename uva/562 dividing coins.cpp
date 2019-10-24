#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define abslt(x) ((x)>=0)? (x): -(x)

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

int coin[110];
int d[110][50010];
 int m;

int dp(int st, int tk, int s)
{
    if(st>m) return abs(tk+tk-s);

//    cout<<st<<" "<<tk<<endl;

    if(d[st][tk]!=-1) return d[st][tk];



    int p, q;
    p=q=INT_MAX;

    p=dp(st+1, tk+coin[st], s);
    q=dp(st+1, tk, s);

//    cout<<p<<" as" <<q<<endl;

    return d[st][tk]=min(p, q);
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {


        cin>>m;

        int s=0;

        for(int i=1;i<=m;i++)
        {
            cin>>coin[i];
            s+=coin[i];
        }

        memset(d, -1, sizeof d);

        cout<<dp(1, 0, s)<<endl;


    }

	return 0;
}

