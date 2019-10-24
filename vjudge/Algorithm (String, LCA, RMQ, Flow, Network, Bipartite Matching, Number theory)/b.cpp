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
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

int a[1000100];

int p[1000100];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    while(cin>>str)
    {
        if(str==".") break;



        memset(a, 0, sizeof a);
        memset(p, 0, sizeof p);

        p[0]=0;
        a[0]=0;

        int i=0, j=1;

        while(j<str.size())
        {
            if(str[j]==str[i])
            {
                a[j]=a[i]+1;
                i++;
                p[j]=i;
                j++;
            }

            else if(i!=0){
                i=p[i-1];

            }

            else
            {
                j++;
            }

        }

        cout<<a[str.size()-1]+1<<endl;
    }


	return 0;
}

