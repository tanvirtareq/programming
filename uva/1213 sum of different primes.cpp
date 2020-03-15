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

#define sz 1200

bool chk[sz];
vector<int> prime;

void seive()
{
    prime.push_back(2);

//    cout<<prime[0]<<endl;

    for(int i=3;i*i<=sz;i+=2)
    {
//        cout<<prime[0]<<endl;
        if(chk[i]==0) {

        for(int j=i+i;j<=sz;j+=i)
            chk[j]=1;

        }
    }

//    cout<<prime[0]<<endl;

    for(int i=3;i<=sz;i+=2)
    {
//        cout<<prime[0]<<endl;
//        cout<<i<<endl;
        if(chk[i]==0){
            prime.push_back(i);
//            cout<<i<<endl;
        }
    }

//    cout<<prime[0]<<endl;

return;

}

int n, k;

int dp(int st, int t, int bk)
{
    if(bk==0) return 1;

    if(prime[st]>t) return 0;

    int p=dp(st+1, t-prime[st], bk-1);
    int q=dp(st+1, t, bk);

    return p+q;
}



int main()
{
    seive();
    while(cin>>n>>k)
    {
        if(n==0 and k==0) break;

        cout<<dp(0 , n, k)<<endl;

    }

	return 0;
}

