#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<li> mxpqli;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;


int main()
{

//    li t=(li)1<<2-1;
//
//    cout<<t<<endl;

    lu q, a;

    cin>>q;

    while(q--)
    {
        cin>>a;

        double x=(double)log((double)a)/log(2.0);

        lu y=(lu)x;

        if(a==((lu)1<<(y+(lu)1))-(lu)1) cout<<1<<endl;

        else{
            li ans=((lu)1<<(y+(lu)1))-(lu)1;
            cout<<ans<<endl;
        }
    }


	return 0;
}
