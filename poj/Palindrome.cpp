
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int M=1000100;
const int kinds=256; /// maximum ascii value of an array character of the string
char str[M];
int k, buc[M], r[M], sa[M], X[M], Y[M], high[M];

bool cmp(int *r, int a, int b, int x)
{
    return (r[a]==r[b] && r[a+x]==r[b+x]);
}


void suffix_array_DA(int n, int m)
{
    int *x=X, *y=Y, i, j, k=0, l;
    memset(buc, 0, sizeof buc);

    for(i=0, i<n;i++)
        buc[x[i]=str[i]]++;
    for(i=n-1;i>=0;i--)
        buc[i]+=buc[i-1];
    for(i=n-1;i>=0;i--)
        sa[--buc[x[i]]]=i;
    for(l=1, j=1;j<n;m=j, l<<=1)
    {
        j=0;
        for(i=n-1;i<n;i++)
            y[j++]=i;
        for(i=0;i<n;i++)
            if(sa[i]>=1)
                j[j++]=sa[i]-1;

    }
}

void build_LCP_array()
{
    ll n = text.size(), i, j, id1, id2;
    ll x1, x2, y1, y2;
    for(i = 1; i < n; i++)
    {
        id1 = arr[i-1].indx;
        id2 = arr[i].indx;

        if(id1<as)
            y1=1;
        else if(id1<bs)
            y1=2;

        if(id2<as)
            y2=1;
        else if(id2<bs)
            y2=2;

        if(y1==y2)
            continue;

        ll x=0;
        for(j = step - 1; j >= 0; j--)
        {
            if(id1<as)
                x1=1;
            else if(id1<bs)
                x1=2;

            if(id2<as)
                x2=1;
            else if(id2<bs)
                x2=2;

            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2] and y1==x1 and y2==x2)
            {
                x += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);

            }

            mx=max(mx, x);

        }

    }
}

void clr()
{
    memset(arr, 0, sizeof arr);
    memset(Rank, 0, sizeof Rank);

}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    for(ll in=1;cin>>a;in++)
    {
        if(a=="END") break;
        clr();
        text=a;
        as=text.size();
        reverse(a.begin(), a.end());
        text+=a;
        bs=text.size();
        text+="$";
        mx=0;
        build_suffix_array();
        build_LCP_array();

        cout<<"Case "<<in<<": ";
        cout<<mx<<endl;
    }

    return 0;
}
