#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        string name;

        int bp, bd, tmp, c;
        char ch;

        cin>>name>>bp>>ch>>tmp>>ch>>tmp>>bd>>ch>>tmp>>ch>>tmp>>c;
//        cout<<name<<" show "<<bp<< " "<<bd<<endl;

        if(bp>=2010)
        {
            cout<<name<<" eligible"<<endl;

        }

        else if(bd>=1991)
        {
            cout<<name<<" eligible"<<endl;
        }

        else if(c>40)
        {
            cout<<name<<" ineligible"<<endl;
        }
        else
        {
            cout<<name<<" coach petition"<<endl;
        }
    }

	return 0;
}

/**

3
elig 2013/09/01 1995/03/12 10
ineligi 2009/09/01 1990/12/12 50
peti 2009/09/01 1990/12/12 35

*/

