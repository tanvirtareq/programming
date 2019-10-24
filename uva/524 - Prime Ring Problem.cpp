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
 int t=1;

 bool prime[40];


void show()
{


    cout<<ans[1];
    for(int i=2;i<=n;i++)
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

    if(state>=n+1){

        if(prime[1+bf])
        show();
        return;
    }

//    if(n-state<7) return;

    for(int i=2;i<=n;i++)
    {
        if(vis[i]==0 and prime[i+bf])
        {
            vis[i]=1;

            ans[state]=i;
            b(state+1, i);

            vis[i]=0;
        }

    }

    return;

}



int main()
{


 prime[2]=1;
prime[3]=1;
prime[5]=1;
 prime[7]=1;
  prime[11]=1;
 prime[13]=1;
 prime[17]=1;
 prime[19]=1;
 prime[23]=1;
 prime[29]=1;
 prime[31]=1;
 prime[37]=1;

bool f=false;
    while(cin>>n)
    {
        if(f) cout<<endl;

        f=true;

        cout<<"Case "<<t++<< ":"<<endl;

        clr(ans);
        clr(vis);

        ans[1]=1;

        b(2, 1);

    }


    return 0;
}

