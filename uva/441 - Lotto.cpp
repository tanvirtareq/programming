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

int n, a[15], ans[15];
bool vis[15];

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
    for(int i=1;i<=6;i++)
        cout<<ans[i]<<" ";

    cout<<endl;

    return;
}

void b(int state, int bf)
{
    //cout<<state<<endl;

    if(state>=7){
        show();
        return;
    }

//    if(n-state<7) return;

    for(int i=bf+1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            ans[state]=a[i];
            b(state+1, i);

            vis[i]=0;
        }

    }

    return;

}

int main()
{

    bool f=false;

    while(cin>>n)
    {
        if(n==0) return 0;

        if(f) cout<<endl;

        f=true;

        clr(a);
        clr(ans);
        clr(vis);

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }

//        show(a);

        sort(a+1, a+n+1);

//        show(a);

        b(1, 0);

//        cout<<endl;

    }


    return 0;
}

/**

7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0

*/
