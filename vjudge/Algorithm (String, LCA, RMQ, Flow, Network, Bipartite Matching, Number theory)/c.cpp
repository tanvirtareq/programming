#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
//#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int>, greater<int> > mnpqi;

struct tr
{
    int child[10]= {0};

    bool isEnd=false;
};

tr a[100100];

int root=0;
int top=0;

bool make_trie(string str)
{
    int nw=root;
    for(int i=0; i<str.size(); i++)
    {
        if(a[nw].isEnd)
            return true;

        else if(a[nw].child[str[i]-'0']==0)
        {
            top++;
            a[nw].child[str[i]-'0']=top;

        }
        nw=a[nw].child[str[i]-'0'];

        if(i==str.size()-1)
        {
            a[nw].isEnd=true;
            break;
        }
    }

    return false;

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin>>t;

    while(t--)
    {
        memset(a, 0, sizeof a);
        root=0;
        top=0;

        cin>>n;
        vector<string>v;

        for(int i=1; i<=n; i++)
        {
            string str;
            cin>>str;
            v.push_back(str);

        }
        sort(v.begin(), v.end());

        bool flag=false;

        for(int i=0; i<v.size(); i++)
        {
            if(make_trie(v[i]))
            {
                flag=true;
//                cout<<v[i]<<endl;
                break;

            }

        }

        if(flag)
        {
            cout<<"NO"<<endl;

        }
        else
            cout<<"YES"<<endl;



    }


    return 0;
}

/**
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
*/

