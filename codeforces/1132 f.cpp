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

template<class x>
void showstack(stack<x> stk)
{
    while(!stk.empty())
    {
        cout<<stk.top();

        stk.pop();

    }

    cout<<endl<<endl;

}

int main()
{

    int n;
    cin>>n;

    cin.ignore();

    map<char, int> mp;

    stack<char> stk;
    int s=0;

            char x;
//        cin>>x;
//
//        char prv=x;

//        mp[prv]++;
//
//        stk.push(x);

    while(n--)
    {

        cin>>x;
//        cout<<x<<endl;

        if(mp[x]<=0 or (!stk.empty() and stk.top()==x))
        {
            stk.push(x);

//            showstack(stk);

            mp[x]++;

        }

        else if(!stk.empty() and mp[x]>0)
        {
            char pv=stk.top();

            while(stk.top()!=x){

            stk.pop();
            mp[pv]--;

            if(mp[pv]<=0) mp[pv]=0;

//            cout<<s<<endl;

            while(!stk.empty() and stk.top()==pv )
            {
                stk.pop();
                mp[pv]--;

                if(mp[pv]<=0) mp[pv]=0;
            }

            s++;

            if(!stk.empty())
            pv=stk.top();

            else break;

//            cout<<s<<endl;

        }
        stk.push(x);
        mp[x]++;

        }

    }

//    cout<<s<<endl;

    while(!stk.empty())
    {

//        cout<<stk.top()<<endl;
         char pv=stk.top();
            stk.pop();

            mp[pv]--;

            if(mp[pv]<=0) mp[pv]=0;

            while(!stk.empty() and  stk.top()==pv )
            {
//                cout<<s<<endl;

                stk.pop();
                mp[pv]--;

                if(mp[pv]<=0) mp[pv]=0;
            }
            s++;

    }

    cout<<s<<endl;

	return 0;
}

/**

4
aaaa

5
sadsa

*/

