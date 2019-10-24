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


int ar[4010][6], n, ans=0;


int inline rec(int l,int tk)
{

//cout<<l<<" "<<tk<<endl;
    if(l==5)
    {
        if(tk==0){

//                cout<<"__________"<<tk<<endl;

//                show(as);

        ans++;
         return 1;
        }
        else return 0;
    }

    int x=0;
    for(int i=1;i<=n;i++)
    {
//        cout<<ar[l][i]<<" ";
//        as[l]=ar[i][l];
        rec(l+1, tk+ar[i][l]);

    }

//    cout<<x<<endl;
    return x;

}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    sci(t);

    while(t--)
    {


//        cin>>n;

sci(n);

        memset(ar, 0, sizeof ar);
        ans=0;

        for(int i=1;i<=n;i++){
//            cin>>ar[i][1]>>ar[i][2]>>ar[i][3]>>ar[i][4];

        sci(ar[i][1]);
        sci(ar[i][2]);
        sci(ar[i][3]);
        sci(ar[i][4]);

        }
        int x=0;

        for(int i=1;i<=n;i++)
        {

            rec(2, ar[i][1]);
//            cout<<endl;

        }

//        cout<<ans<<endl;

printf("%d\n", ans);

    }

	return 0;
}

/**

1
6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45

1
2
1 2 3 4
-1 -2 -3 -4
0 0 0 0

*/
