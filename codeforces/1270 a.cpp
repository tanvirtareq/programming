#include<bits/stdc++.h>
#define ll long long
#define dbg(a) cout<<#a<<"="<<a<<endl;
using namespace std;
int main()
{
    int q;
    scanf("%d", &q);

    for(int in=1;in<=q;in++)
    {
        ll h, m;
        cin>>h>>m;
        cout<<24*60-60*h-m<<endl;

    }
    return 0;
}








