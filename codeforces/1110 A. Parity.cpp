#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define  for(n)   for(int i=1;i<=n;i++)

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

string inline multi(string a, string b)
{
    if(a==b) return a;

    else return "odd";



}

string inline pls(string a, string b)
{
    if(a==b) return "even";

    else return "odd";



}


int main()
{

    int b, k;

    cin>>b>>k;

    if(b%2==0)
    {
        int n;
        while(cin>>n)
        {

        }
        if(n==0) cout<<"even"<<endl;

        else if(n%2==0)

        cout<<"even"<<endl;

        else
            cout<<"odd"<<endl;

    }
    else
    {
        string ans="even";
        int n;

        while(cin>>n)
        {
            if(n==0) continue;
            string x;
            if(n%2==0)
            {
                x="even";

            }
            else x="odd";

            ans=pls(ans, x);

        }
        cout<<ans<<endl;

    }

	return 0;
}

/**

3 5
1 1 0 1 0

*/
