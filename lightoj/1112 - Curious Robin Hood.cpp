#include<bits/stdc++.h>
    #include<cstdio>
    #include<cstring>
typedef long long int lld;
     
    using namespace std;
     
    int iniat_segtree(int node, int b, int e, int ar[], int tree[], int leaf[])
    {
        //cout<<node<<" "<<b<<"  "<<e<<endl; 
     
        if(b==e)
        {
            tree[node]=ar[b];
            //cout<<node<<"  "<<tree[node]<<endl;
            leaf[b]=node;
            return tree[node];
        }
        int left=2*node;
        int right=2*node+1;
     
        int mid=(b+e)/2;
     
        int p1=iniat_segtree(left, b, mid, ar, tree, leaf);
        int p2=iniat_segtree(right, mid+1, e, ar, tree, leaf);
        tree[node]=p1+ p2;
     //cout<<node<<"  "<<tree[node]<<endl;
     
        return tree[node];
     
     
     
    }
     
     
    int treesum(int node, int b, int e, int i, int j, int ar[], int tree[])
    {
        if(b>=i&&e<=j)
        {
            return tree[node];
        }
     
        else if(b>j||e<i)
        {
            return 0;
        }
     
        else
        {
            int left=2*node;
            int right=2*node+1;
     
            int mid=(b+e)/2;
     
            int p1=treesum(left, b, mid,i, j, ar, tree);
            int p2=treesum(right, mid+1, e,i,j, ar, tree);
     
            return p1+p2;
     
        }
     
    }

    void updatesegtree(int node, int tree[], int newval, int leaf[])
    {
        int lv=leaf[node];
        int x=tree[lv];
        int cut=x-newval;
        int y=lv;
        while(y>0)
        {
            tree[y]=tree[y]-cut;
            y=y/2;
        }
        return;

    }

    void updatesegtree(lld node, lld b, lld e, lld i, lld ar[], lld tree[],lld newval)
    {
        if(b==i and e==i)
        {
            tree[node]=newval;
            return;
        }
     
        else if(b>i||e<i)
        {
            return ;
        }
     
        else
        {
            lld left=2*node;
            lld right=2*node+1;
     
            lld mid=(b+e)/2;
     
            updatesegtree(left, b, mid,i, ar, tree, newval);
            updatesegtree(right, mid+1, e,i, ar, tree, newval);
            tree[node]=tree[left]+tree[right];
     
            return ;
     
        }
     
    }
     
     
    int main()
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        
        int t, n, q, typ, i, v, j;

        scanf("%d", &t);

        for(int k=1;k<=t;k++)
        {
            printf("Case %d:\n", k);

            scanf("%d%d", &n, &q);

            int ar[100100], tree[300100], leaf[1000100];

            for(int l=1;l<=n;l++)
            {
                scanf("%d", &ar[l]);
            }

            iniat_segtree(1, 1, n, ar, tree, leaf);

            while(q--)
            {
                scanf("%d", &typ);
                scanf("%d", &i);

                if(typ==1)
                {
                    

                    printf("%d\n", ar[i+1]);
                    ar[i+1]=0;
                    updatesegtree(i+1,tree, (lld)0, leaf);

                }

                else if (typ==2)
                {
                    /* code */
                    scanf("%d", &v);

                    ar[i+1]=ar[i+1]+v;

                    updatesegtree(i+1, tree, ar[i+1], leaf);
                }

                else
                {
                    scanf("%d", &j);
                    int sum=treesum((lld)1, (lld)1, n, i+1, j+1, ar, tree);

                    printf("%d\n",sum );
                }

            }
        }
     
        return 0;
    }
 
 
