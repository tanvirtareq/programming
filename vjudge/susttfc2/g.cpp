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

int mn[110], fv[110], n, m;

int tab[110][11000];

int dp(int s, int tk, int f)
{
//    cout<<f<<endl;

    if(s>n)
    {
//        cout<<f<<" "<<tk<<endl;

        if(tk>2000 and tk<=m+200)
        {
            return f;
        }

        else if(tk<=m) return f;

        else return 0;

    }

    if(tab[s][tk]!=-1) return tab[s][tk];

    int p=dp(s+1, tk, f);

    int q=0;
    q=dp(s+1, tk+mn[s], f+fv[s]);

    return tab[s][tk]=max(p, q);



}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    while(cin>>m>>n)
    {


        memset(tab, -1, sizeof tab);
        memset(mn, 0, sizeof mn);
        memset(fv, 0, sizeof fv);

        int f, p, c;

        for(int i=1;i<=n;i++)
        {
            cin>>mn[i]>>fv[i];


        }

        int t=dp(1, 0, 0);

        cout<<t<<endl;


    }

	return 0;
}

/**

1900 3
2000 5
1950 2
101 1

*/




