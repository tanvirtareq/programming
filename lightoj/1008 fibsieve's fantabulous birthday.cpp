#include<bits/stdc++.h>
#define lim 100000000
#define brk  if(s>=lim) break
#define inp a[++s]=make_pair(r, c)
#define prnt //cout<<s<<"="<<r<<" "<<c<<endl
typedef long long unsigned llu;

using namespace std;

pair<int, int> a[lim];

//
//struct my{
//int first, second;
//};
//my a[lim];

//void make_pair(int r, int c, llu s)
//{
//    a[s].first=r;
//    a[s].second=c;
//    return;
//}

void fn()
{
    llu s=0, r=1, c=1;

    inp;
    prnt;
    while(1)
    {
        ++r;
        inp;
        prnt;
        if(s>=lim) break;
        for(c=1+1;c<=r;++c)
        {
            inp;
            prnt;
            brk;

        }
        brk;
        c--;
        for(r=c-1;r>=1;r--)
        {
            inp;
            prnt;
            brk;
        }
        brk;
        r++;
        ++c;
        inp;
        prnt;
        brk;
        for(r=1+1;r<=c;r++)
        {
            inp;
            prnt;
            brk;
        }
        brk;
        r--;

        for(c=r-1;c>=1;c--)
        {
            inp;
            prnt;
            brk;
        }
        brk;
        c++;
    }

    return;
}

int main() {

    fn();

    llu t, s;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>s;
        cout<<"Case "<<i<<": "<<a[s].second<<" "<<a[s].first<<endl;
    }

    return 0;
}

