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

bool chk[sz];
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


}



int main()
{

    string x;

    cin>>x;

    if(x.size()==1)
    {
        cout<<x<<endl;
        return 0;
    }

    li pr=power(9, x.size()-1);

    if(x[0]>'1') pr=(x[0]-1-'0')*pr;

    li s=1, i=1;

    li f=0;

    for(i=1;i<x.size();i++)
    {
        if(x[i-1]<=x[i])
            s*=x[i-1]-'0';

        else{
                f=1;
            break;

        }
    }

    if(f){

        if(x[i-1]=='1')
        {
            cout<<pr<<endl;
            return 0;
        }

        s*=x[i-1]-'0'-1;


    while(i<x.size())
    {
        s*=9;
        i++;
    }
    }

    else
    {
        s*=x[x.size()-1]-'0';
    }

//    cout<<s<<endl;



    if(s<pr) s=pr;

    cout<<s<<endl;
	return 0;
}

