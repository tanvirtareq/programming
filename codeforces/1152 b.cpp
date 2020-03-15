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

int find0(int a)
{
    int x=log(a)/log(2)+1;

//    cout<<a<<endl;

    int ss=0;
    while(ss==0)
    {
        if(a&(1<<x))
        {
            break;
        }
        else x--;
    }

    if(x>2){
        if((a&1)==0 and (a&(1<<1))==0  ) return 1;

    }

    if(power(2, x)==a)
    {
        return 1;
    }

    for(int i=x;i>=0;i--)
    {
        if(a&(1<<i)){}
//        cout<<1;
        else{
            if(i<=2)
            {
//                if((a&1)==0)  return 0;
                return 0;

            }

            if((a&1)==0 and (a&(1<<1))==0) return i;

            return i+1;
//                cout<<0;
        }

    }
//    cout<<endl;

    return -1;


}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin>>n;

    if(n==1){
        cout<<0<<endl;
        return 0;
    }

    vector<int> v;

    int x=find0(n);
//    showbinaryrepresentation_of_pos_int(n);
//    showbinaryrepresentation_of_pos_int((1<<x)-1);
//    cout<<x<<endl;
    while(x!=-1)
    {
        v.push_back(x);
        n^=(1<<x)-1;
        n++;
//        cout<<n<<endl;
//        showbinaryrepresentation_of_pos_int(n);
        x=find0(n);
//        cout<<x<<endl;
    }

    cout<<2*v.size()<<endl;

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

	return 0;
}
