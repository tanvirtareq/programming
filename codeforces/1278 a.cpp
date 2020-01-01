#include<bits/stdc++.h>
#define ll long long
#define lu long long unsigned
#define dbg(a) cout<<#a<<"="<<a<<endl;
#define ii pair<int, int>
#define vi vector<int>

using namespace std;

int eq(string a, string b)
{
    sort(b.begin(), b.end());
    if(a==b) return 1;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string x, y;
        cin>>x>>y;
        sort(x.begin(), x.end());
        int fc=x.size();
        int i=0, j=fc-1;
        int tmp=0;
        while(j<y.size())
        {
            string xx;
            for(int k=i;k<=j;k++)
            {
                xx.push_back(y[k]);
            }
            if(eq(x, xx)){

             tmp=1;
              break;
            }
            i++;
            j++;
        }
        if(tmp) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }



    return 0;
}
