#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned

using namespace std;

int n, ar[200], br[200];

int fnd( int x)
{
    for(int i=1;i<=n;i++) if(ar[i]==x) return i;

}
void rot( int st, int ed)
{
    int fc=ar[ed];
    for(int i=ed;i>st;i--) ar[i]=ar[i-1];
    ar[st]=fc;
}

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
	    cin>>n;
	    for(int i=1;i<=n;i++)
        {
            cin>>ar[i];
            br[ar[i]]=i;
        }
        int trc=1;
        for(int i=1;i<n;i++)
        {
            int id=fnd(i);
            if(id==trc) trc++;
            if(id>trc)
            {
                rot(trc, id);
                trc=id;
            }
        }
        for(int i=1;i<=n;i++) cout<<ar[i]<<" ";
        cout<<endl;
	}
	return 0;
}
