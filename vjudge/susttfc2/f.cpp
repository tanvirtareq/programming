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

template<class T>
void inline showbinaryrepresentation_of_pos_int(T a)
{
    T x=log(a)/log(2)+1;

//    cout<<a<<endl;

    for(int i=x;i>=0;i--)
    {
        if(a&((T)1<<i))
        cout<<1;
        else cout<<0;

    }
    cout<<endl;

    return;

}

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


/// for seive prime

#define sz 5000

bool chk[sz+5];
vector<lu> prime;

void seive()
{
    prime.push_back(2);

    for(lu i=3;i*i<=sz;i+=2)
    {
        if(chk[i]==0) {

        for(lu j=i+i;j<=sz;j+=i)
            chk[j]=1;

        }
    }


    for(lu i=3;i<=sz;i+=2)
    {
        if(chk[i]==0){
            prime.push_back(i);
        }
    }

   // cout<< prime[0] <<endl;


}

#define eps 10e-6


double distsq(pair<int , int> a, pair<int, int> b)
{
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));

}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while(cin>>n)
    {
        pair<int , int> p[n+10];

        for(int i=0;i<n;i++)
        {
            int x, y;

            cin>>x>>y;

            p[i].first=x;
            p[i].second=y;
        }

        int ans=0;

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++)
                {
                    double d1=distsq(p[i], p[j]);
                    double d2=distsq(p[k], p[j]);
                    double d3=distsq(p[i], p[k]);
//                    cout<<d1<<" "<<d2<<" "<<d3<<endl;

                    if(abs(d1+d2-d3)<eps) continue;
                    if(abs(d1+d3-d2)<eps) continue;
                    if(abs(d3+d2-d1)<eps) continue;

                    if(abs(d1-d2)<eps and abs(d1-d3)>=eps) ans++;
                    else if(abs(d1-d3)<eps and abs(d1-d2)>eps) ans++;
                    else if(abs(d3-d2)<eps and abs(d1-d3)>eps) ans++;


                }


        cout<<ans<<endl;

    }


	return 0;
}



