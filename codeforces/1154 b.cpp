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

#define sz 100000

bool chk[sz+5];
vector<int> prime;

void seive()
{
    prime.push_back(2);

    for(int i=3;i*i<=sz;i+=2)
    {
        if(chk[i]==0) {

        for(int j=i+i;j<=sz;j+=i)
            chk[j]=1;

        }
    }


    for(int i=3;i<=sz;i+=2)
    {
        if(chk[i]==0){
            prime.push_back(i);
        }
    }

   // cout<< prime[0] <<endl;


}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    set<int> st;
    set<int>:: iterator ist;

    vector<int> v;

    map<int, int> mp;

    while(t--)
    {
        int x;
        cin>>x;

        if(mp[x]==0)
        {
            mp[x]=1;
            v.push_back(x);
        }
    }

    sort(v.begin(), v.end());

    if(v.size()==1)
    {
        cout<<0<<endl;

        return 0;
    }

    if(v.size()>3){
        cout<<-1<<endl;
    }

    if(v.size()==2)
    {
        if((v[0]+v[1])%2==0)
        {
            cout<<(v[1]+v[0])/2-v[0];
            return 0;
        }

        else cout<<v[1]-v[0]<<endl;

        return 0;

    }

    if(v[1]-v[0]==v[2]-v[1])
    {
        cout<<v[1]-v[0]<<endl;

        return 0;
    }

    else cout<<-1<<endl;


	return 0;
}
