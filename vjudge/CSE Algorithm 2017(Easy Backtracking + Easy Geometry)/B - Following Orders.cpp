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


string x;

bool cnst[30][30];

char a[30];

int ans[30];

map<char,vector< char> > mp;
map<char, bool> vis;

void show()
{
    for(int i=0;i<x.size();i++)
        cout<<a[i];

    cout<<endl;

}


int b(int state)
{
//    cout<<state<<endl;

    if(state==x.size()) show();

    for(int i=0;i<x.size();i++)
    {
        char current_chr=x[i];

        if(vis[current_chr]==0 )
        {
            if(mp[current_chr].size()!=0){

                bool flag=0;

            for(int i=0;i<mp[current_chr].size();i++)
            {
                char chk_chr=mp[current_chr][i];

                if(vis[chk_chr]==0) flag=1;
            }

            if(flag==1) continue;
            }

            a[state]=x[i];
            vis[x[i]]=1;
            b(state+1);

            vis[x[i]]=0;
        }
    }
    return 0;
}

int main()
{
string st;

//cout<<endl;

bool f=false;
    while(getline(cin, st))
    {
        if(f) cout<<endl;

        f=true;

        clr(cnst);
        clr(a);
        clr(ans);
//        clr(vis);
        x.clear();
        mp.clear();
        vis.clear();



        string y;
        getline(cin, y);

        for(int i=0;i<st.size();i+=2)
            x.push_back(st[i]);

//        cout<<x<<endl;

        sort(x.begin(), x.end());

        for(int i=0;i<y.size();i+=4)
        {
            mp[y[i+2]].push_back(y[i]);
//            cout<<y[i]<<" "<<y[i+2]<<endl;

        }

        b(0);

//        cout<<endl;

        st.clear();

    }




	return 0;
}
/**

a b f g
a b b f
v w x y z
v y x v z v w v

*/
