
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX =100004;
struct info
{
    int tup[2], indx; ///tup[0] = prev rank, tup[1] = new rank
    bool operator<(const info &a)const
    {
        return tup[0] != a.tup[0]? tup[0] < a.tup[0] : tup[1] < a.tup[1];
    }
} arr[MAX];
int Rank[18][MAX], LCP[MAX], step;
string text;
string a, b, c;
int as, bs, cs;

void build_suffix_array(void)
{
    int n = text.size(), jump;
    for(int j = 0; j < n; j++)
    {
        Rank[0][j] = text[j];
        memset(arr[j].tup, 0,sizeof(arr[j].tup));
    }
    for(step = 1, jump = 1; jump <= n; step++, jump <<= 1)
    {
        for(int j = 0; j <=n; j++)
        {
            arr[j].indx = j;
            arr[j].tup[0] = Rank[step - 1][j];
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
    LCP[1]=0;
    int n = text.size(), i, j, id1, id2, id3;
    int x1, x2, x3, y1, y2, y3;
    set<int>st;
    for(i = 2; i < n; i++)
    {
        id1 = arr[i-2].indx;
        id2 = arr[i-1].indx;
        id3=arr[i].indx;

        if(id1<as)
            y1=1;
        else if(id1<bs)
            y1=2;
        else if(id1<cs)
            y1=3;


        if(id2<as)
            y2=1;
        else if(id2<bs)
            y2=2;
        else if(id2<cs)
            y2=3;


        if(id3<as)
            y3=1;
        else if(id3<bs)
            y3=2;
        else if(id3<cs)
            y3=3;

        if(y1==y2 or y1==y3 or y2==y3)
            continue;

        LCP[i] = 0;
        for(j = step - 1; j >= 0; j--)
        {
            if(id1<as)
                x1=1;
            else if(id1<bs)
                x1=2;
            else if(id1<cs)
                x1=3;


            if(id2<as)
                x2=1;
            else if(id2<bs)
                x2=2;
            else if(id2<cs)
                x2=3;


            if(id3<as)
                x3=1;
            else if(id3<bs)
                x3=2;
            else if(id3<cs)
                x3=3;

            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id1]==Rank[j][id3] && Rank[j][id2] and y1==x1 and y2==x2 and y3==x3)
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
                id3 += (1 << j);

            }

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
    for(int in=1; in<=t; in++)
    {
        clr();


        cin>>a>>b>>c;
        text=a;
        as=text.size();
        text+=b;
        bs=text.size();
        text+=c;
        cs=text.size();
        text+="$";
        build_suffix_array();
        build_LCP_array();

        ll mx=0;
        for(int i=2; i<text.size(); i++)
            mx=max(mx, (ll)LCP[i]);

        cout<<"Case "<<in<<": ";
        cout<<mx<<endl;
    }

    return 0;
}

/**


aab
baa
baaab

aaaac
caddcb
cdbb

ca
ccb
cd

*/

