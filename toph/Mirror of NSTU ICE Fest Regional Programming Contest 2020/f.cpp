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


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    string s;
    cin>>n>>k>>s;
    if(k==0)
    {
        cout<<s<<endl;
        return 0;
    }
    int mp[30]={0};
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]-'a']++;
    }

    char ch='#';
    for(int i=25;i>=0;i--)
    {
        if(mp[i]==k)
        {
            ch=(char)('a'+i);
            break;
        }
    }
    if(ch!='#')
    {
        string x[k+10];
        int ct=0;
        while(ct<k)
        {
            int f=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]==ch)
                {
                    f++;
                    if(f-1==ct) x[ct].push_back(ch);
                    else continue;
                }
                else x[ct].push_back(s[i]);
            }
            ct++;
        }
        sort(x, x+k);
        cout<<x[0]<<endl;
    }
    else cout<<s<<endl;


	return 0;
}




