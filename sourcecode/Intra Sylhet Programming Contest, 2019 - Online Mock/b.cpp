
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



int main()
{
    int t;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        double a, b, c;
        double x, y;
        char ch;

        cin>>a>>b>>c>>x;
        cin>>ch;
        cin>>y;

        double s=(a+b+c)/2.0;

        double area=sqrt(s*(s-a)*(s-b)*(s-c))/4.0;

//        printf("Case %d: %.2lf\n", area);

        cout<<"Case "<<i<<": ";
        cout<<fixed<<setprecision(2)<<area<<endl;

    }

	return 0;
}
/**

4

3 4 5 1 : 1

3 4 5 1 : 1

3 4 5 1 : 1

3 4 5 1 : 1

*/
