#include<bits/stdc++.h>



#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cput<<#a<<" = "<<a<<endl

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

void solv1(string s)
{
    ll x=0;
    for(int i=0;i<s.size();i++)
    {
        if((s[i]-'0')%2==1) x++;
    }

    if(x==0)
    {
        cout<<-1<<endl;
        return;
    }
    if(x%2==0)
    {
        cout<<s<<endl;
        return;
    }
    int f=0;
    for(int i=0;i<s.size();i++)
    {
        if(f==1) cout<<s[i];
        else
        {
            if((s[i]-'0')%2==1)
            {
                f=1;
                continue;
            }
            else cout<<s[i];
        }
    }
    cout<<endl;
    return;
}

void slv2(string s)
{
    ll x=0;
    string y;
    for(int i=0;i<s.size();i++)
    {
        if((s[i]-'0')%2==1)
        {
            y.push_back(s[i]);
            if(y.size()==2) break;
        }
    }
    if(y.size()==2)
    {
        cout<<y<<endl;
        return;
    }
    else{
        cout<<-1<<endl;
        return;
    }
//    if(x==0)
//    {
//        cout<<-1<<endl;
//        return;
//    }
//
//    int f=0;
//    for(int i=0;i<s.size();i++)
//    {
//        if((s[i]-'0')%2==1)
//        {
//            cout<<s[i];
//            if(f==0) f=1;
//            else if(f==1) return;
//        }
//    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
//        if((s[s.size()-1]-'0')%2==1)
//        {
//            solv1(s);
//        }
//        else slv2(s);
        slv2(s);
    }

	return 0;
}

