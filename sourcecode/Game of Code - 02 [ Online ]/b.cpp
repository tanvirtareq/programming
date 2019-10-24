#include<bits/stdc++.h>

typedef long long int lld;
typedef long long unsigned llu;

using namespace std;

int main()
{
	set<llu>st;

	lld xs,ys,xf,yf,t,n;
	llu r2;

	cin>>t;
	while(t--)
	{
	    st.clear();
		cin>>xs>>ys;
		cin>>n;
		while(n--)
		{
			cin>>xf>>yf;
			r2=(xs-xf)*(xs-xf)+(ys-yf)*(ys-yf);
			st.insert(r2);
		}
		cout<<st.size()<<endl;
	}
	return 0;
}
