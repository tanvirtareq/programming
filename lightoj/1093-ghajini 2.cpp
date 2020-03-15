#include<bits/stdc++.h>
#define inf 100000000
using namespace std;

typedef long long int li;

int mxtree[400010], v[200010], mntree[400010];

int buildmn(int node, int start, int ed)
{
//    cout<<node<<" "<<start<<" "<<ed<<endl;

    if(start>ed) return inf;
    if(start==ed)
    {
        mntree[node]=v[start];

//        cout<<tree[node]<<endl;
        return mntree[node];
    }

    int left=2*node;
    int right=2*node+1;

    int m=(start+ed)/2;

    int x=min(buildmn(left, start, m), buildmn(right, m+1, ed));

//    cout<<x<<endl;

    return mntree[node]=x;


}


int buildmx(int node, int start, int ed)
{
//    cout<<node<<" "<<start<<" "<<ed<<endl;

    if(start>ed) return 0;
    if(start==ed)
    {
        mxtree[node]=v[start];

//        cout<<tree[node]<<endl;
        return mxtree[node];
    }

    int left=2*node;
    int right=2*node+1;

    int m=(start+ed)/2;

    int x=max(buildmx(left, start, m), buildmx(right, m+1, ed));

//    cout<<x<<endl;

    return mxtree[node]=x;


}

int fndmx(int node ,int rst, int red,int start, int ed)
{
    if(start>ed) return 0;

    if(start>red or rst>ed) return 0;

    if(start<=rst and ed>=red) return mxtree[node];

    int left=2*node;
    int right=2*node+1;

    int m=(rst+red)/2;

    return max(fndmx(left, rst, m, start, ed), fndmx(right , m+1, red, start, ed));


}

int fndmn(int node ,int rst, int red,int start, int ed)
{
    if(start>ed) return inf;

    if(start>red or rst>ed) return inf;

    if(start<=rst and ed>=red) return mntree[node];

    int left=2*node;
    int right=2*node+1;

    int m=(rst+red)/2;

    return min(fndmn(left, rst, m, start, ed), fndmn(right , m+1, red, start, ed));


}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    int t;
    scanf("%d", &t);

    for(int i=1;i<=t;i++)
    {
       int n, d;
//       cin>>n>>d;
        scanf("%d%d", &n, &d);

       for(int j=1;j<=n;j++){
//            cin>>v[j];
            scanf("%d", &v[j]);
       }


//    cout<<v[3]<<endl;

       buildmx(1, 1, n);
       buildmn(1, 1, n);


//       cout<<tree[3]<<endl;

//cout<<fndmn(1, 1, n, 2, 6)<<endl;

       int dif=0;

//       cout<<dif<<endl;

        int j;

       for(int k=1,j=k+d-1;j<=n;k++, j++)
       {
           int x=fndmx(1, 1, n, k, j)-fndmn(1, 1 ,n ,k, j);

           dif=max(dif, x);
//           cout<<dif<<endl;

       }

//       cout<<"Case "<<i<<": "<<dif<<endl;
        printf("Case %d: %d\n", i, dif);
    }

    return 0;
}

/**
1
46 8
90 55 122 65 124 3 112 86 58 46 59 74 14 87 116 103 13 6 1 26 116 82 98 112 117 16 55 55 40 60 123 2 115 117 67 111 120 51 70 51 98 1 125 112 88 113

*/

