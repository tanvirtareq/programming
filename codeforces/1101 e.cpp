#include<bits/stdc++.h>
#define pii pair<llu, llu>
#define inf ULLONG_MAX
//typedef pair<int, int> pii;
typedef long long unsigned llu;
typedef long long int lld;
using namespace std;

 string x;

//int dp(int pos, ib, ic, int v)
//{
//    if(ib==2 and ic==2)
//        return v;
//    if(pos>x.size())
//    {
//        return -1;
//    }
//
//    int v1=dp(pos+1, ib, ic, v-1);
//
//    int v2=0;
//
//    if()
//
//    if()
//
//}
//

int main()
{
    int n, l=0, h=0;
//    cin>>n;
//    cin.ignore();
    std :: ios :: sync_with_stdio(false);
    cin.tie(0);
   cin >> n;
   cin.ignore();
    while(n--)
    {
        char ch;
//        cin>>ch;
   cin >> ch;
        if(ch=='+')
        {
            int a, b;
          cin>>a>>b;
            int ll=min(a, b);
            int hh=max(a, b);
            l=max(l, ll);
            h=max(h, hh);


        }

        if(ch=='?')
        {
            int a, b;
//            cin>>a>>b;
cin >> a >> b;

            if(min(a, b)>=l and max(a, b)>=h)
            {
//                cout<<"YES"<<endl;
cout << "YES" << endl;
            }
            else
            cout << "NO" << endl;
        }

    }


    return 0;
}
///  [|||::::|||||::::||||]

