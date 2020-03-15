#include<bits/stdc++.h>
#define mfm 4000000

using namespace std;

int n, t[mfm], j, a[mfm], mx[mfm], mn[mfm];
char ch;

void update(int node, int start, int end, int l, int r, int add)
{
    if (l > r)
        return;
    if (l == start && r == end)
    {
        t[node] += add;
        mn[node]+=add;
        mx[node]+=add;
    }
    else
    {
        int tm = (start + end) / 2;
        update(node*2, start, tm, l, min(r, tm), add);
        update(node*2+1, tm+1, end, max(l, tm+1), r, add);
        mn[node]=min(mn[2*node], mn[2*node+1])+t[node];
        mx[node]=max(mx[2*node], mx[2*node+1])+t[node];
    }
}


int get(int node, int start, int end, int pos)
{
    if (start == end)
        return t[node];
    int tm = (start + end) / 2;
    if (pos <= tm)
        return t[node] + get(node*2, start, tm, pos);
    else
        return t[node] + get(node*2+1, tm+1, end, pos);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    cin.ignore();
    j=1;
    for(int i=1; i<=n; i++)
    {
        cin>>ch;
        if(ch=='R') j++;

        else if(ch=='L') j=max(1, j-1);

        else if(ch=='(')
        {
            int flt=a[j];
            a[j]=1;
            update(1, 1, n, j, n, -flt+1);
        }

        else if(ch==')')
        {
            int flt=a[j];
            a[j]=-1;
            update(1, 1, n, j, n, -flt-1);
        }
        else
        {
            int flt=a[j];
            a[j]=0;
            update(1, 1, n, j, n, -flt);
        }
        int x=get(1, 1, n, n);
        if(mn[1]<0 or x!=0) cout<<-1<<" ";
        else cout<<mx[1]<<" ";
    }
    return 0;
}

/**
11
(R)R(R(R)R)

3
(R)

12
)R)R)R)LL(L(


4
)(R)


*/

