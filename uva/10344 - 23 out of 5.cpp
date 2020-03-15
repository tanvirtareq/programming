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
    for(int i=1;i<=6;i++)
        cout<<ans[i]<<" ";

    cout<<endl;

    return;
}

int b(int state, int bf)
{
    //cout<<state<<endl;

    if(state>=6){
        if(bf==23){
//            cout<<x<<endl;
            return 1;
        }

        return 0;
    }


    if(flg==0)
    {
        flg=1;
        for(int i=1;i<=5;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;

                x.push_back(i+'0');
                if(b(state+1, a[i])) return 1;

                x.pop_back();
                vis[i]=0;

            }

        }

        return 0;

    }


    for(int i=1;i<=5;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;

            x.push_back('+');
            x.push_back(i+'0');
            if(b(state+1, bf+a[i])) return 1;
             x.pop_back();
             x.pop_back();

            x.push_back('-');
            x.push_back(i+'0');
            if(b(state+1, bf-a[i])) return 1;



//            if(b(state+1, a[i]-bf)) return 1;
             x.pop_back();
             x.pop_back();

            x.push_back('*');
            x.push_back(i+'0');
//            if(bf!=0)
            if(b(state+1, bf*a[i])) return 1;
             x.pop_back();
             x.pop_back();

            vis[i]=0;
        }

    }

    return 0;

}



int main()
{
    bool f=false;
    while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5])
    {

        flg=0;

        clr(vis);
        x.clear();

        if(a[1]==0) return 0;

//        if(f) cout<<endl;
        f=true;

        if(b(1, 0)==0) cout<<"Impossible"<<endl;

        else cout<<"Possible"<<endl;

    }

    return 0;
}

/**

1 1 1 1 1
1 2 3 4 5
2 3 5 7 11
0 0 0 0 0


44 2 27 30 29

23 16 43 7 27
*/

