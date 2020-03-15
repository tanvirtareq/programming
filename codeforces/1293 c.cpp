#include<bits/stdc++.h>
#define ll long long

ll A[1000000], tree[1000000], a[5][1000000];

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}


int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

using namespace std;
int main()
{
    ll n, q;
    cin>>n>>q;
    while(q--)
    {
        ll x, y;
        cin>>x>>y;
        a[x][y]=(a[x][y])?0:1;
        if(x==1)
        {
            if(a[1][y]==1 and (a[2][y]==1 || (y-1>0 and a[2][y-1]==1 ) || (y+1<=n and a[2][y+1]==1)))
            {
                update(1, 1, n, y, 1);
            }
            else
                update(1, 1, n, y, 0);
        }
        else if(x==2)
        {
            for(ll i=max(1LL, y-1); i<=min(n, y+1); i++)
            {
                if(a[1][i]==1 and (a[2][i]==1 || (i-1>0 and a[2][i-1]==1 ) || (i+1<=n and a[2][i+1]==1)))
                {
                    update(1, 1, n, i, 1);
                }
                else
                    update(1, 1, n, i, 0);
            }
        }
        if(tree[1])
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}


