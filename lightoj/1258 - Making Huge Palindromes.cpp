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


void find_lps(string pat, int lps[])
{
    int i=0, j=0;

    lps[0]=0;
    i=1;

    while(i<pat.size())
    {
        if(pat[i]==pat[j])
        {
            j++;
            lps[i]=j;
            i++;
        }

        else
        {
            if(j==0){
                lps[i]=0;
                i++;
            }
            else j=lps[j-1];

        }

    }
    return;

}

int Search(string str, int lps[])
{
    int i=0;
    int j=str.size()-1;

    while(i<j)
    {
        if(str[i]==str[j])
        {
            i++;
            j--;
        }
        else
        {
            if(i==0) j--;

            else
            i=lps[i-1];

        }

    }

    if(i==j) return 2*i+1;
    return 2*i;

}

int cnt(string str)
{
    reverse(str.begin(), str.end());

//    cout<<str<<endl;

    int lps[1000010];

    find_lps(str, lps);

//    cout<<"yes"<<endl;

    int x=Search(str, lps);
//    cout<<x<<endl;

    return 2*str.size()-x;

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {

        string x;

        cin>>x;

        cout<<"Case "<<i<<": "<<cnt(x)<<endl;

    }

	return 0;
}

/**

a
ab
aba
abba
abcdccba
abababccbaba

*/


