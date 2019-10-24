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
typedef priority_queue<int, vector<int>, greater<int> > mnpqi;

template<class T>
void inline showbinaryrepresentation_of_pos_int(T a)
{
    T x=log(a)/log(2)+1;

//    cout<<a<<endl;

    for(int i=x; i>=0; i--)
    {
        if(a&((T)1<<i))
            cout<<1;
        else
            cout<<0;

    }
    cout<<endl;

    return;

}

li inline power(li b, li p)
{
    if(b==2)
        return (li)1<<(p);

    if(p==0)
        return 1;

    if(p==1)
        return b;

    li x=power(b, p/2);

    if(p&1)
    {
        return b*x*x;
    }

    else
        return x*x;

}


/// for seive prime

#define sz 100000

bool chk[sz+5];
vector<int> prime;

void seive()
{
    prime.push_back(2);

    for(int i=3; i*i<=sz; i+=2)
    {
        if(chk[i]==0)
        {

            for(int j=i+i; j<=sz; j+=i)
                chk[j]=1;

        }
    }


    for(int i=3; i<=sz; i+=2)
    {
        if(chk[i]==0)
        {
            prime.push_back(i);
        }
    }

    // cout<< prime[0] <<endl;


}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    li q;
    cin>>q;

    while(q--)
    {
        li k, n, a, b;
        cin>>k>>n>>a>>b;

        li l=ceil((double)(k-a)/(double)a);

//        cout<<l<<endl;

        if(l>=n)
        {
            cout<<n<<endl;
            continue;
        }

        li r=k-a*l;

        li x=ceil((double)(r-b)/(double)b);

        if(l+x>=n)
        {
            cout<<min(l,  n)<<endl;

            continue;
        }

        int flag=0;

        li aa=k-1;


        while(l)
        {
            cout<<l<<endl;

            l=ceil((double)(b*n+b-k)/(double)(b-a));

            cout<<l<<endl;

            r=k-a*l;

            x=ceil((double)(r-b)/(double)b);





            if(l>=0)
            {


                cout<<min(l,  n)<<endl;

                flag=1;
            }

            break;



        }

        if(flag==0)
            cout<<-1<<endl;


    }


    return 0;
}

