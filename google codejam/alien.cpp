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

map<pair<int,int>, int> mp;
map<pair<int ,int> , int> ::iterator it;

int r, c, t, n;

int bc(int i,  int j, int cv)
{
//    if(i==2 and j==3) cout<<"2 3"<<endl;

    if(cv==r*c) return 1;

    if(i>r or j>c) return 0;

    for(int k=1;k<=r;k++)
    {

        for(int l=1;l<=c;l++)
        {

//            if(i==2 and j==3) cout<<mp[make_pair(k, l)]<<endl;

            if(k!=i and l!=j and (i+j)!=(k+l) and (i-j)!=(k-l) and mp[make_pair(k, l)]==0)
            {
//                if(i==2 and j==3)
//                cout<<"mp"<<endl;

                mp[make_pair(k, l)]=cv+1;
                if(cv+1==r*c)  return 1;
                if(bc(k, l, cv+1)) return 1;

                mp[make_pair(k, l)]=0;

            }

        }
    }

    return 0;
}

void show()
{
    map<int, pair<int, int> > ans;

    for(it=mp.begin();it!=mp.end();it++)
    {
        ans[it->second]=it->first;

    }

    for(int i=1;i<=r*c;i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    return;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        int n;

        cin>>n;


    }

	return 0;
}


