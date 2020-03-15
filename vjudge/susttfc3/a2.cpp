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

int rec(int m, int n, bool p)
{
    if(m==n) return p;  //winner

    int x, y;

    if(m+1<=n){
    x=rec(m+1, n, !p);

     if(x==p){
//            cout<<m<<" "<<n<<" "<<p<<endl;
//            cout<<" winner "<<p<<endl;
            return p;
    }
    }

    if(2*m<=n){
    y=rec(2*m, n, !p);

     if(y==p){
//            cout<<m<<" "<<n<<" "<<p<<endl;
//            cout<<" winner "<<p<<endl;
            return p;
    }
    }

//            cout<<m<<" "<<n<<" "<<p<<endl;
//
//            cout<<" winner "<<!p<<endl;
    return !p;

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int f=rec(1, n, 1);

        cout<<f<<endl;

    }

	return 0;
}

/**

1000
1
1
2
0
3
1
4
0
5
0
6
0
7
0
8
0
9
1
10
0
11
1
12
0
13
0
14
0
15
0
16
0
17
0
18
0
19
0
20
0
21
0
22
0
23
0
24
0
25
0
26
0
27
0
28
0
29
0
30
0
31
0
32
0
33
1

*/


