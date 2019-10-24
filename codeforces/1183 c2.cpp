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

pair<int, int> extendedEuclidean(int a,  int b)
{
    pair<int, int> p, q;

    if(a%b==0)
    {
        p.first=0;
        p.second=1;
        return p;
    }

    q=extendedEuclidean(b, a%b);
    p.first=q.second;
    p.second=q.first+(-a/b)*q.second;
    return p;

}

pair<int, int> extendedEuclideanCover(int a, int b)
{
    pair<int, int> p;
    p=extendedEuclidean(abs(a), abs(b));

    if(a<0) p.first=-p.first;
    if(b<0) p.second=-p.second;

    return p;

}

pair<int, int>  find_one_solution_of_linear_diophantine_equation(int a, int b, int c)
{
    pair<int, int> p, q;

    int g=__gcd(abs(a) , abs(b));

    if(c%g!=0)
    {
        cout<<"no solution"<<endl;
        return p;
    }

    q=extendedEuclideanCover(a,b);

    p.first=q.first*c/g;
    p.second=q.second*c/g;

    return p;

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

        li x=ceil((double)(k-b*n)/(double)(a-b));

        li y=ceil((double)(k-a*n)/(double)(b-a));

        pair<int, int> p=find_one_solution_of_linear_diophantine_equation(a, b, k-1);

        int g=-n;

        p.first=p.first+g;
        p.second=p.second-g*(a/b);

        x=p.first;
        y=p.second;

        cout<<x<<" "<<y<<endl;

        if(x+y>=n and a*x+b*y<k)
        {
            cout<<x<<endl;
            continue;

        }

        x--;

        if(x+y>=n and a*x+b*y<k)
        {
            cout<<x<<endl;
            continue;

        }

        y--;

        if(x+y>=n and a*x+b*y<k)
        {
            cout<<x<<endl;
            continue;

        }

        x++;

        if(x+y>=n and a*x+b*y<k)
        {
            cout<<x<<endl;
            continue;

        }

        cout<<-1<<endl;





    }


    return 0;
}


