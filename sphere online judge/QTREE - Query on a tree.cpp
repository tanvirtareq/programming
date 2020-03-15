#include<bits/stdc++.h>

using namespace std;

#define root 0
#define N 10100
#define LN 14
#define endl '\n'

vector<int> adj[N] /** adjacency matrix*/, costs[N]/** cost of edge*/, indexx[N]/** index of edge */;
int baseArray[N]; /** segment tree build base on baseArray */
int ptr; /** ptr is for base array */
int chainNo;
int chainInd[N];/** indicate chainNo of node  */
int chainHead[N]; /** index of this array is chainNo */
int posInBase[N]; /** node position in base array */
int depth[N]; /** depth of the node */
int pa[LN][N]; /** pa[i][j] indicate 2^i th ancestor of node j */
int otherEnd[N]; /** otherEnd[i]=v  if  i'th edge's two edjancent node u and v
                    and depth[v]>depth[u] */
int subsize[N]; /** subsize[i] = size of the the sub tree which root is i  */
int st[N*6]; /** segment tree; */
int qt[N*6]; /** query_tree*/


/**
 * make_tree:
 * Used to construct the segment tree. It uses the baseArray for construction
 */

void make_tree(int cur, int s, int e) /** s and e are node , it build path from s to e*/
{
    if(s==e-1)
    {
        st[cur]=baseArray[s];
        return;
    }

    int c1=cur<<1, c2=c1|1, m=(s+e)>>1;
    make_tree(c1, s, m);
    make_tree(c2, m, e);
    st[cur]=st[c1]>st[c2]? st[c1]:st[c2];
    return;

}

/**
 * Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo++ ensures that we are creating a new chain for each normal child.
 */

/**
 * update_tree:
 * Point update. Update a single element of the segment tree.
 */
void update_tree(int cur, int s, int e, int x, int val) {
	if(s > x || e <= x) return;
	if(s == x && s == e-1) {
		st[cur] = val;
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	update_tree(c1, s, m, x, val);
	update_tree(c2, m, e, x, val);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
	return;
}


/**
* change:
* We just need to find its position in segment tree and update it
*/
void change(int i, int val) {
	int u = otherEnd[i];
	update_tree(1, 0, ptr, posInBase[u], val);
	return;
}

void HLD(int curNode, int cost, int prev)
{
    if(chainHead[chainNo]==-1)
    {
        chainHead[chainNo]=curNode;
    }
    chainInd[curNode]=chainNo;
    posInBase[curNode]=ptr;/** Position of this node in baseArray which we will use in Segtree*/
    baseArray[ptr++]=cost;

    int sc=-1; /** special child which has biggest subtree*/
    int ncost; /** cost from curNode to sc*/
    /**Loop to find special child*/
    for(int i=0; i<adj[curNode].size(); i++)
    {
        if(adj[curNode][i]!=prev)
        {
            if(sc!=-1 || subsize[sc]<subsize[adj[curNode][i]])
            {
                sc=adj[curNode][i];
                ncost=costs[curNode][i];
            }
        }

    }

    if(sc!=-1)
    {
        /** Expand the chain*/
        HLD(sc, ncost, curNode);
    }

    for(int i=0; i<adj[curNode].size(); i++)
    {
        if(adj[curNode][i]!=prev)
        {
            if(sc!=adj[curNode][i])
            {
                chainNo++;
                HLD(adj[curNode][i],costs[curNode][i], curNode);
            }
        }
    }
    return;

}

/**
 * dfs used to set parent of a node, depth of a node, subtree size of a node
 */
void dfs(int cur, int prev, int _depth=0) /** prev is parent of cur node*/
{
    pa[0][cur]=prev;
    depth[cur]=_depth;
    subsize[cur]=1;
    for(int i=0; i<adj[cur].size(); i++)
    {
        if(adj[cur][i]!=prev)
        {
            otherEnd[indexx[cur][i]]=adj[cur][i];
            dfs(adj[cur][i], cur, _depth+1);
            subsize[cur]+=subsize[adj[cur][i]];
        }
    }
    return;

}

void initforlca(int n)
{
    for(int i=i; i<LN; i++)
        for(int j=0; j<n; j++)
            if(pa[i-1][j]!=-1)
                pa[i][j]=pa[i-1][pa[i-1][j]];
    return;
}

/**
 * query_tree:
 * Given S and E, it will return the maximum value in the range [S,E)
 */

void query_tree(int cur, int s, int e, int S, int E)
{
    if(s >= E || e <= S)
    {
        qt[cur] = -1;
        return;
    }
    if(s >= S && e <= E)
    {
        qt[cur] = st[cur];
        return;
    }
    int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
    query_tree(c1, s, m, S, E);
    query_tree(c2, m, e, S, E);
    qt[cur] = qt[c1] > qt[c2] ? qt[c1] : qt[c2];
    return;
}

/**
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */
int query_up(int u, int v)
{
    if(u==v)
        return 0;
    int uchain; /** chainNo of u*/
    int vchain=chainInd[v]; /** chainNo of v*/
    int ans =-1;

    while(1)
    {
        uchain=chainInd[u];
        if(uchain==vchain)
        {
            /** Both u and v are in the same chain, so we need to query from u to v, update answer and break.
              We break because we came from u up till v, we are done
            */

            if(u==v)
                break;
            query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
            // Above is call to segment tree query function
            if(qt[1] > ans)
                ans = qt[1]; // Update answer
            break;
        }

        query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
        // Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
        // start till head. We then update the answer
        if(qt[1] > ans)
            ans = qt[1];
        u = chainHead[uchain]; // move u to u's chainHead
        u = pa[0][u]; //Then move to its parent, that means we changed chains

    }
    return ans;

}


/**
 * LCA:
 * Takes two nodes u, v and returns Lowest Common Ancestor of u, v
 */

int LCA(int u, int v)
{
    if(depth[u]<depth[v])
        swap(u, v);
    int diff=depth[u]-depth[v];
    for(int i=0; i<LN; i++)
        if((diff>>i)&1)
            u=pa[i][u];
    if(u==v)
        return u;
    for(int i=LN-1; i>=0; i--)
    {
        if(pa[i][u]!=pa[i][v])
        {
            u=pa[i][u];
            v=pa[i][v];
        }
    }
    return pa[0][u];
}

void query(int u, int v)
{
    /**
     * We have a query from u to v, we break it into two queries, u to LCA(u,v) and LCA(u,v) to v
     */

    int lca=LCA(u, v);
    int ans=query_up( u, lca);
    int temp=query_up( v, lca);
    if(temp > ans) ans = temp; // take the maximum of both paths
	printf("%d\n", ans);

}

void clr(int n)
{
    ptr=0;
    for(int i=0;i<n;i++)
    {
        adj[i].clear();
        costs[i].clear();
        indexx[i].clear();
        chainHead[i]=-1;
        for(int j=0;j<LN;j++) pa[j][i]=-1;
    }
    return;
}
int main()
{
    int t;
    scanf("%d", &t);
    int f=0;
    while(t--)
    {
//        if(f) cout<<endl;
        f=1;
        int n;
        scanf("%d", &n);
        ptr=0;
        // Cleaning step, new test case
		for(int i=0; i<n; i++) {
			adj[i].clear();
			costs[i].clear();
			indexx[i].clear();
			chainHead[i] = -1;
			for(int j=0; j<LN; j++) pa[j][i] = -1;
		}
        for(int i=1;i<n;i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            a--;b--;
            adj[a].push_back(b);
            costs[a].push_back(c);
            indexx[a].push_back(i-1);


            adj[b].push_back(a);
            costs[b].push_back(c);
            indexx[b].push_back(i-1);
        }
        chainNo=0;
        dfs(0, -1);
        HLD(0, -1, -1);
        make_tree(1, 0 , ptr);

        // Below Dynamic programming code is for LCA.
		for(int i=1; i<LN; i++)
			for(int j=0; j<n; j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];

        while(1)
        {
            char s[100];
            scanf("%s", s);

            if(s[0]=='D') break;
            if(s[0]=='C')
            {
                int a, b;
                scanf("%d %d", &a, &b);
                change(a-1, b);
            }
            if(s[0]=='Q')
            {
                int a, b;
                scanf("%d %d", &a, &b);
                query(a-1, b-1);
            }
        }
    }


    return 0;
}
