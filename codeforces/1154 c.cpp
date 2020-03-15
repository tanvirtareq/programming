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


    int a[]={0, 0, 1, 2, 2, 2, 3, 3};
    int b[]={0, 1, 1, 1 ,2, 2, 2, 2};
    int c[]={0, 0, 0, 0, 0, 1, 1,2};

int strt(int i, int *x, int *y, int *z)
{
//    if(i!=0)
//    {
//        x+=a[i];
//        y+=b[i];
//        z+=c[i];
//
//        int ans=0;
//
//        while(x>=3 and y>=2 and z>=2)
//        {
//            ans+=7;
//
//            x-=3;
//            y-=2;
//            z-=2;
//
//        }
//
//        if(ans!=0) return ans-i;
//
//        else return 0;
//    }
//
    int ans=0;

        while(*x>=3 and *y>=2 and *z>=2)
        {
            ans+=7;
            *x-=3;
            *y-=2;
            *z-=2;

        }

        if(ans!=0) return ans;

        else return 0;




}

int End(int i,int *x, int *y, int *z)
{
//    cout<<"asj"<<i<<endl;
    int mx=0;

    for(int j=i;j<=7;j++)
    {
        if(*x>=(a[j]-a[i-1]) and *y>=(b[j]-b[i-1]) and *z>=(c[j]-c[i-1]))
        {
            mx=j-i+1;
//            cout<<mx<<endl;
        }

    }

    return mx;

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int x, y, z, ans=0, mx=0;

    cin>>x>>y>>z;

    for(int i=1;i<=7;i++)
    {
        ans=strt(i, &x, &y, &z);

//        cout<<ans<<endl;

        ans+=End(i, &x, &y, &z);

        mx=max(mx, ans);
    }

    cout<<mx<<endl;

	return 0;
}


