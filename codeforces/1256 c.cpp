#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned

using namespace std;

int main()
{
    int n, m, d;
    cin>>n>>m>>d;
    int rv[n+10]= {0};
    int c[n+10];
    int s=0;
    for(int i=1; i<=m; i++)
    {
        cin>>c[i];
        s+=c[i];
    }
    int ct=n-s;

    if((d-1)*(m+1)<ct)
        return cout<<"NO"<<endl, 0;

    cout<<"YES"<<endl;


    int x=1;
    int id=1;
    for(int i=1; i<=n; i++)
    {
        if(ct and x)
            rv[i]=0, ct--;

        else
        {
            int y=c[id];
            id++;
            while(y--)
            {
                rv[i]=id-1;
                i++;
            }
            i--;
        }
        x=(x+1)%d;
    }
    for(int i=1; i<=n; i++)
        cout<<rv[i]<<" ";
    return 0;
}
