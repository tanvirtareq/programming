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



li inline power(li b, li p)
{
    if(b==2) return (li)1<<(p);

    if(p==0) return 1;

    if(p==1) return b;

    li x=power(b, p/2);

    if(p&1)
    {
        return b*x*x;
    }

    else return x*x;

}

li lg(li n)
{
    li x=0;

    if(n==0) return 0;

    while(n>>1)
    {
        x++;
        n=n>>1;

    }
//    cout<<x<<endl;
    return x;

}

void show(int i, int ar[])
{
    int br[10000];
    br[0]=1;

//    cout<<br[0]<<endl;

    for(int j=1;j<=i-1;j++)
    {
        br[j]=ar[j-1]+ar[j];
    }
    br[i]=1;

    int od=0, ev=0;

    cout<<i<<endl;

    for(int j=0;j<=i;j++)
    {
        ar[j]=br[j];
        if(ar[j]%2==0) ev++;
        else od++;

        cout<<ar[j]<<" ";
    }
    cout<<endl;

    cout<<ev<<" "<<od<<endl<<endl;

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    li n;

    cin>>t;

    int ar[10000];
    ar[0]=1;

    for(int i=0;i<=t+1;i++)
    {
        if(i==0)
        {
            cout<<ar[0]<<endl;
        }

        else if(i==1)
        {
            ar[1]=1;
            cout<<ar[0]<<" "<<ar[1]<<endl;
        }

        else
        {
           show(i,ar);
        }


    }



	return 0;
}



