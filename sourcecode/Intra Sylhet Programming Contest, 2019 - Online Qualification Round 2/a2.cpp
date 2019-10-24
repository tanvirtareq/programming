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

int d[1005][1005];

int ar[1005];

int dp(int f, int l, map<int, int> mp)
{
    if(d[f][l]!=-1) return d[f][l];

    if(f+1>=l) return d[f][l]=0;

    int tk=ar[l]-ar[f-1];

//    if(tk%2==1) return 0;



    if(tk%2==0  and  mp[tk/2+ar[f-1]]!=0){

//     cout<<l<< " "<<f<<endl;
            return d[f][l]=l-f+1;
    }


    int x=dp(f+1, l, mp);

//    if(x!=0) return d[f][l]=x;

    int y=dp(f, l-1,  mp);

    return d[f][l]=max(x, y);


}

int main()
{
    int t;

    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);

        memset(ar, 0, sizeof ar);

        scanf("%d", &ar[1]);

        map<int, int> mp;

        mp[ar[1]]=1;

        ar[0]=0;

        for(int i=2;i<=n;i++)
        {
            scanf("%d", &ar[i]);
            ar[i]+=ar[i-1];

            mp[ar[i]]=i;
        }

        memset(d, -1 , sizeof d);

//        cout<<dp(1, n, ar, mp)<<endl;

        printf("%d\n", dp(1, n, mp));


    }


	return 0;
}
