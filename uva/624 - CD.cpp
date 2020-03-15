#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define clr(x) memset(x, 0, sizeof x )
#define mems(x, a) memset(x, a, sizeof x)


using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

int n, a[30], ans[15], t;
unsigned tab[30][3000];
bool vis[15], flg;

string x;

void show()
{
    cout<<ans[1];
    for(int i=2;i<=6;i++)
        cout<<" "<<ans[i];

    cout<<endl;

    return;
}

void show(int ans[])
{
    for(int i=1;i<=t;i++)
        cout<<ans[i]<<" ";

    cout<<endl;

    return;
}

void show(int r, int c)
{
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
        cout<<tab[i][j]<<" ";

    cout<<endl;

    return;

}

int b(int state, int bf)
{
    //cout<<state<<endl;

    if(bf>n) return tab[state][bf]= INT_MAX;

    if(state>=t+1){
        return tab[state][bf]= n-bf;

    }

    int p=b(state+1, bf);
    int q=b(state+1, bf+a[state]);

//    cout<<"for "<<state<<endl;

//    cout<<p<< " "<<q<<endl;

    if(p<q)
    {
//        cout<<a[state]<<endl;

        ans[state]=0;
    }
    else ans[state]=a[state];

    return tab[state][bf]=min(p, q);

}

int trck(int state, int bf)
{
//    cout<<endl<<state<<bf<<endl;

    if(state>t) return 0;

    if(bf>n) return INT_MAX;

    if(tab[state+1][bf]<=tab[state+1][bf+a[state]])
    {
        trck(state+1, bf);
        return 0;

    }

//    cout<<tab[state+1][bf]<<" "<<tab[state+1][bf+a[state]]<<endl;

    cout<<a[state]<< " ";

    trck(state+1, bf+a[state]);

    return 0;

}



int main()
{

    while(cin>>n)
    {
        cin>>t;

        clr(a);
        clr(ans);

        mems(tab, UINT_MAX);

//        cout<<tab[1][1]<<endl;

        for(int i=1;i<=t;i++)
        {
            cin>>a[i];

        }

        int x=b(1, 0);

        trck(1, 0);
        cout<<"sum:"<<n-x<<endl;

//        show()

    }

    return 0;
}

/**
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2
*/

