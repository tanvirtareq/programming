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


li mn[110], fv[110], n, m;

li tab[110][4000*102];

li dp(li s, li tk, li f)
{

    if(s>n)
    {

        if(tk>2000 and tk<=m+200)
        {
            return f;
        }

        else if(tk<=m) return f;

        else return 0;

    }



    if(tab[s][tk]!=-1) return tab[s][tk];

    li p=dp(s+1, tk, f);

    li q=0;

    if(tk<=m+200)
    q=dp(s+1, tk+mn[s], f+fv[s]);

    return tab[s][tk]=max(p, q);

}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    while(cin>>m>>n)
    {


        memset(tab, -1, sizeof tab);
        memset(mn, 0, sizeof mn);
        memset(fv, 0, sizeof fv);

        li f, p, c;

        for(li i=1;i<=n;i++)
        {
            cin>>mn[i]>>fv[i];

        }

        li t=dp(1, 0, 0);

        cout<<t<<endl;


    }

	return 0;
}


