#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef vector<li>::iterator vit;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;



/// for seive prime

#define sz 100000

//
//void seive()
//{
//    prime.push_back(2);
//
////    cout<<prime[0]<<endl;
//
//    for(int i=3;i*i<=sz;i+=2)
//    {
//        if(chk[i]==0) {
//
//        for(int j=i+i;j<=sz;j+=i)
//            chk[j]=1;
//
//        }
//    }
//
//
//    for(int i=3;i<=sz;i+=2)
//    {
//        if(chk[i]==0){
//            prime.push_back(i);
////            cout<<prime[prime.size()-1]<<endl;
//        }
//    }
//
//
//}



int main()
{


    bool chk[sz+10];
    vector<li> prime;
    prime.push_back(2);

//    cout<<prime[0]<<endl;

    for(li i=3;i*i<=sz;i+=2)
    {
        if(chk[i]==0) {

        for(li j=i+i;j<=sz;j+=i)
            chk[j]=1;

        }
    }


    for(li i=3;i<=sz;i+=2)
    {
        if(chk[i]==0){
            prime.push_back(i);
//            cout<<prime[prime.size()-1]<<endl;
        }
    }

    for(int i=0;i<26;i++)
    {
        cout<<prime[i]*prime[i+1]<<" ";
    }


    li t;
    cin>>t;

    for(li i=1;i<=t;i++)
    {
        li n ,l;

        cin>>n>>l;

        li ar[27], x,a1, b1;

        map<li, li> mp, vis;

        map<li, pair<li, li> > m;

        set<li> st;
        set<li>::iterator itst;

//        li k=z-25;

        li br[l+10];

        for(int j=1;j<=l;j++)
        {
            cin>>br[j];
            if(vis[br[j]]==0)
            {
                for(int k=0;prime[k]*prime[k]<=br[j];k++)
                {
                    if(br[j]%prime[k]==0)
                    {
                        st.insert(br[j]/prime[k]);
                        st.insert(prime[k]);
                        m[br[j]]=make_pair(br[j]/prime[k], prime[k]);

                        break;
                    }

                }

            }

        }

        vector<li> v;

        for(itst=st.begin();itst!=st.end();itst++)
        {
            if(*itst!=0)
            v.push_back(*itst);
        }

        for(int j=0;j<v.size();j++)
        {
            if(v[j]!=0)
            mp[v[j]]=j;
        }

//        cout<<k<<endl;

//        for(li j=0;k<=z;j++)
//        {
//            m[prime[k]]=j;
////            cout<<prime[k]<<" "<<j<<endl;
//
//            k++;
//        }

//        cout<<m[prime[25]]<<endl;

//        for(li j=1;j<=26;j++)
//            cout<<prime[m[j]]<<endl;
//        cout<<"Yes"<<endl;

        x=br[1];

        a1=m[x].first;
        b1=m[x].second;

//        for(li j=0;j<=z;j++)
//        {
//            if(x%prime[j]==0)
//            {
//                a1=prime[j];
//                b1=x/prime[j];
//
//                cout<<"yes"<<j<<endl;
//                break;
//            }
//
//        }

//        cout<<a1<<" "<<b1<<endl;
//
////        cout<<"yes"<<endl;
//
//        cin>>x;

        x=br[2];
        li a2, b2;

        a2=m[x].first;

        b2=m[x].second;
//
//        for(li j=z-25;j<=z;j++)
//        {
//            if(x%prime[j]==0)
//            {
//                a2=prime[j];
//                b2=x/prime[j];
//                break;
//            }
//
//        }
//


//        cout<<"YES"<<endl;
        li a, b, c;

        if(b1==b2)
        {
            a=a1;
            b=b1;
            c=b2;
        }

        if(b1==a2)
        {
            a=a1;
            b=b1;
            c=b2;
        }

        if(a1==a2)
        {
            a=b1;
            b=a1;
            c=b2;
        }

        if(a1==b2)
        {
            a=b1;
            b=a1;
            c=a2;
        }


//        cout<<a<<" "<<b<<endl;

        vector<li> str;
        str.push_back(a);
        str.push_back(b);
        str.push_back(c);

//        cout<<str[0]<<" "<<str[1]<<" "<<str[2]<<endl;

        for(li j=3;j<=l;j++)
        {
            x=br[j];
            if(x!=0 and str[str.size()-1]!=0)
            str.push_back(x/str[str.size()-1]);

        }

        cout<<"Case #"<<i<<": ";
        for(li j=0;j<str.size();j++)
        {
            cout<<(char)('A'+mp[str[j]]);
        }
        cout<<endl;

    }

	return 0;
}

/**

2
103 31
217 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053
10000 25
3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 5335543
*/



