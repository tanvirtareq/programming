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

    string x, y, z;
    cin>>x;

    y.clear();

    for(li i=0;i<x.size();i++)
    {
        if(x[i]!='a')
        {
            y.push_back(x[i]);

        }

    }

//    cout<<y<<endl;

    if(y.size()%2==1)
    {
        cout<<":("<<endl;
        return 0;
    }

    if(y.size()==0)
    {
        cout<<x<<endl;
        return 0;
    }

    li tt=y.size()/2;

    li flg=0;
    li i, j;
    for(i=tt-1, j=x.size()-1; i>=0, j>=0; i--, j--)
    {
        if(i<0 or j<0) break;

//        cout<<i<<" "<<j<<endl;

        if(y[i]!=y[i+tt] or x[j]!=y[i])
        {
//            cout<<y[i]<<" "<<j<<endl;

            flg=1;
            break;
        }

        else{

                x.pop_back();
                y.pop_back();
//                i--;
//                j--;
        }
    }

    if(flg==1 or y.size()!=tt)
    {
        cout<<":("<<endl;
        return 0;
    }
    else
    {
        for(li i=x.size()-1, j=y.size()-1;j>=tt;j--, i--)
        {
            if(x[i]==y[j])
                x.pop_back();

            else break;

        }

        cout<<x<<endl;

    }


	return 0;
}
