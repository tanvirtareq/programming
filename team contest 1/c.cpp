#include<bits/stdc++.h>
typedef unsigned long long ull;

using namespace std;

int main()
{
//    ios_base::sync_with_stdio(false);
    ull t;
//    cin>>t;
    scanf("%llu", &t);
    while(t--)
    {
        ull n;
//        cin>>n;
        scanf("%llu", &n);
        map<ull, ull> mp;
        ull x=0;
        for(ull i=0;i<n;i++)
        {
            ull ch;
//            cin>>ch;
            scanf("%llu", &ch);
            mp[ch]=i;
        }
        for(ull i=0;i<n;i++)
        {
            ull ch;
//            cin>>ch;
            scanf("%llu", &ch);
            if(i>mp[ch])
            x+=i-mp[ch];
            else x+=mp[ch]-i;
        }
//        cout<<x/2<<endl;
        printf("%llu\n", x/2);


    }

    return 0;
}
