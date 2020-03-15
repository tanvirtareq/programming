#include<bits/stdc++.h>

using namespace std;

class node{
    public:

    int val;

    node *child[11];

    bool isChild[10], isEnd;

    node()
    {
        memset(isChild, 0, sizeof isChild);

       isEnd=0;
    }

};

node *root=new node();


int trie(string x)
{
    node *par=root;

    for(int i=0;i<x.size();i++)
    {
        if(par->isEnd!=0 ) return 1;

        if(par->isChild[x[i]-'0']==0)
        {
            node *nw=new node();

            par->child[x[i]-'0']=nw;

            par->isChild[x[i]-'0']=1;
        }

        par=par->child[x[i]-'0'];

    }
    par->isEnd=1;

    return 0;

}

void del(node *cur)
{
    for(int i=0;i<=9;i++)
    {
        if(cur->isChild[i]!=0){
            del(cur->child[i]);
            cur->isChild[i]!=0;
        }
    }

    delete cur;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;

    cin>>t;

    for(int i =1;i<=t;i++)
    {
        cin>>n;
//        cin.ignore();
//        cin.ignore();

        int f=0;

        root=new node();

        vector<string> nmb;

        string x;

        for(int j=1;j<=n;j++)
        {
            cin>>x;
            nmb.push_back(x);
        }

        sort(nmb.begin(), nmb.end());

//        node nd[10000];
        for(int j=0;j<nmb.size();j++)
        {
            x=nmb[j];
            f=trie(x);

            if(f==1)
            {
                cout<<"Case "<<i<<": "<<"NO"<<endl;
                break;
            }

        }

        if(f==0)  cout<<"Case "<<i<<": "<<"YES"<<endl;

        del(root);

//        cout<<"asf"<<endl;



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
