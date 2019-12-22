#include<bits/stdc++.h>
#define ll long long
#define lu long long unsigned
#define dbg(a) cout<<#a<<"="<<a<<endl;
#define ii pair<int, int>
#define vi vector<int>

using namespace std;
string x, y;

int chk(int pre, int pst)
{


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--)
    {

        cin>>x>>y;
        int ar[200]={0}, br[200]={0};
        for(int i=0;i<x.size();i++)
        {
            ar[x[i]-'a']++;
        }
        for(int i=0;i<y.size();i++)
        {
            if(ar[y[i]-'a']==0)
            {
                br[i]=1;
            }
        }

        int pre, post;

        for(int i=0;i<y.size();i++)
        {
            if(br[i]==0)
            {
                pre=i;
                break;
            }
        }
        int fl=0;

        for(int i=pre;i<y.size();i++)
        {
            if(pre==-1 and br[i]==0)
                pre=i;
            if(pre!=-1 and br[i]==1)
            {
                if(chk(pre, i))
                {
                    int fl=1;
                    break;
                }
                pre=-1;
            }
        }
        if(fl) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

//        int pre, post;
//        for(int i=0;i<y.size();i++)
//        {
//            if(br[i]==0) {
//                    pre=i;
//            break;
//            }
//        }
//        for(int i=y.size();i>=0;i--)
//        {
//            if(br[i]==0) {
//                    post=i;
//            break;
//            }
//        }
//        int fl=0;
//        for(int i=pre+1;i<post;i++)
//        {
//            if(br[i]==1)
//            {
//                fl=1;
//                break;
//            }
//            ar[y[i]-'a']--;
//        }
//        for(int i=0;i<26;i++)
//        {
//            if(ar[i]!=0)
//            {
//                fl=1;
//                break;
//            }
//        }
//        (fl)? cout<<"NO"<<endl:cout<<"YES"<<endl;
    }


    return 0;
}
