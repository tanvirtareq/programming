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


#define sz 1000

bool chk[sz+5];
vector<int> prime;

void seive()
{
    prime.push_back(2);

    for(int i=3;i*i<=sz;i+=2)
    {
        if(chk[i]==0) {

        for(int j=i+i;j<=sz;j+=i)
            chk[j]=1;

        }
    }


    for(int i=3;i<=sz;i+=2)
    {
        if(chk[i]==0){
            prime.push_back(i);
        }
    }

   // cout<< prime[0] <<endl;


}
vector<int> v[1010];
map<char,  int>mp;
map<char,  int>:: iterator it;
map<int, int> root2numb;
map<int, char> root2char;
map<int, char>::iterator  itroot2char;
bool vis[1010];
char ans[1010];

int find_numb_comp(int rt)
{
    if(vis[rt]==1) return 0;
    int ct=0;
    queue<int>q;
    q.push(rt);
    vis[rt]=1;

    while(!q.empty())
    {
        rt=q.front();
        q.pop();
        ct++;
        for(int i=0;i<v[rt].size();i++)
        {
            if(vis[v[rt][i]]==0)
            {
                vis[v[rt][i]]=1;
                q.push(v[rt][i]);
            }

        }
    }
    return ct;
}

void asgn(int rt, char x)
{
    queue<int> q;

    q.push(rt);

    while(!q.empty())
    {
        rt=q.front();
        q.pop();
        ans[rt]=x;

        for(int i=0;i<v[rt].size();i++)
        {
//            cout<<v[rt][i]<<endl;
            if(vis[v[rt][i]]==0)
            {
                vis[v[rt][i]]=1;
                q.push(v[rt][i]);
            }

        }
    }
    return;

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    seive();

    string str;
    cin>>str;

    for(int i=0;i<str.size();i++)
    {
        mp[str[i]]++;

    }



    for(int i=0;prime[i]<=str.size();i++)
    {
        for(int j=2;j<=str.size()/prime[i];j++)
        {
//            cout<<prime[i]<<" "<<j*prime[i]<<endl;
            v[j*prime[i]].push_back(prime[i]);
            v[prime[i]].push_back(j*prime[i]);
        }

    }
//    cout<<str<<endl;

    int flag=0;
    for(int i=1;i<=str.size();i++)
    {
        if(vis[i]==0)
        {
            root2numb[i]=find_numb_comp(i);
//            cout<<i<<" "<<root2numb[i]<<endl;

            int ct=-1;

            for(it=mp.begin();it!=mp.end();it++)
            {
                if(ct==-1 and it->second>=root2numb[i])
                {
                    ct=it->second;
                    root2char[i]=it->first;
                }

                else if(ct!=-1 and it->second>=root2numb[i] and ct>it->second)
                {
                    ct=it->second;
                    root2char[i]=it->first;
                }

            }

            if(ct==-1)
            {
                flag=1;
                cout<<"NO"<<endl;
                return 0;
                break;
            }
//            cout<<ct<<endl;

//            cout<<root2char[i]<<" "<<i<<endl;

//            root2numb[i]-=ct;
            mp[root2char[i]]-=root2numb[i];
        }

        if(flag==1)
        {
            cout<<"NO"<<endl;
            return 0;
        }


    }

    memset(vis, 0, sizeof vis);

    for(itroot2char=root2char.begin();itroot2char!=root2char.end();itroot2char++)
    {
        asgn(itroot2char->first, itroot2char->second);
//        cout<<str<<endl;

    }
//    cout<<str<<endl;

    cout<<"YES"<<endl;

    for(int i=1;i<=str.size();i++)
    {
        cout<<ans[i];
    }
    cout<<endl;

	return 0;
}


