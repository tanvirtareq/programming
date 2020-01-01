#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX =100005;
struct info
{
    int tup[2], indx; ///tup[0] = prev rank, tup[1] = new rank
    bool operator<(const info &a)const
    {
        return tup[0] != a.tup[0]? tup[0] < a.tup[0] : tup[1] < a.tup[1];
    }
}arr[MAX];
int Rank[20][MAX], LCP[MAX], step;
string text;

void build_suffix_array()
{
    int n = text.size(), jump;
    for(int j = 0; j < n; j++)
    {
        Rank[0][j] = text[j]; ///rank suffixes according to 1st char
        memset(arr[j].tup, 0,sizeof(arr[j].tup));
    }
    for(step = 1, jump = 1; jump <= n; step++, jump <<= 1)
    {
        for(int j = 0; j <=n; j++)
        {
            arr[j].indx = j;
            arr[j].tup[0] = Rank[step - 1][j]; /// what i was in prev step
            arr[j].tup[1] = j + jump < n? Rank[step - 1][j + jump] : -1;
        }
        sort(arr, arr + n);
        Rank[step][arr[0].indx] = 0;
        for(int j = 1; j < n; j++)
            Rank[step][arr[j].indx] = arr[j].tup[0] == arr[j - 1].tup[0] &&
            arr[j].tup[1] == arr[j - 1].tup[1] ? Rank[step][arr[j - 1].indx] : j;
    }
}

void build_LCP_array()
{
    LCP[0] = 0;
    int n = text.size(), i, j, id1, id2;
    for(i = 1; i < n; i++)
    {
        id1 = arr[i - 1].indx;
        id2 = arr[i].indx;
        LCP[i] = 0;
        for(j = step - 1; j >= 0; j--)
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2])
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
    }
}

void clr()
{
    memset(arr, 0, sizeof arr);
    memset(Rank, 0, sizeof Rank);
    memset(LCP, 0, sizeof LCP);

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   int t;
   cin>>t;
   for(int in=1;in<=t;in++)
   {
       clr();
       int p, q;
       cin>>text>>p>>q;
       text+='$';
        build_suffix_array();
        build_LCP_array();

        ll sum=0;
        int n=text.size();
        for(int i=1;i<n;i++)
        {
            ll k=min(n-arr[i].indx-1, q)-max(LCP[i], p-1);
            if(k>0) sum+=k;
        }

       cout<<"Case "<<in<<": ";
       cout<<sum<<endl;
   }

    return 0;
}
