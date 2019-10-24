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

    li t, n;
    cin>>t;

    for(li i=1;i<=t;i++)
    {
        cin>>n;

        li ar[n+10][n+10], a[n+10];

        memset(ar, 0, sizeof ar);
        memset(a, 0, sizeof a);

        for(li j=1;j<=n;j++)
        {


            cin>>a[j];
            showbinaryrepresentation_of_pos_int(a[j]);
        }

        li mx=0;
        for(li j=1;j<=n;j++)
            for(li k=j;k<=n;k++)
        {

            ar[j][k]=ar[j][k-1]^a[k];

            cout<<j<<" "<<k<<" "<<ar[j][k]<<endl;
            if(mx<ar[j][k]) mx=ar[j][k];
        }


        cout<<"Case "<<i<<": "<<mx<<endl;

    }

	return 0;
}

/**

8
14 11 2 3 9 11 8 2

4
4 12 5 11


*/
