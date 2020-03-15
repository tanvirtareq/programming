#include<bits/stdc++.h>
#define sz 10000
#define sq 100


using namespace std;

vector<int>p;
bool chk[sz+1];

void seive()
{
    chk[1]=1;
    for(int i=3;i*i<=sz;i=i+2)
    {
        if(chk[i]==0)
        {
            for(int j=i*i;j<=sz;j=j+2*i)
            {
                chk[j]=1;
            }
        }
    }
    p.push_back(2);
    for(int i=3;i<=sz;i=i+2)
    {
        if(chk[i]==0) p.push_back(i);
    }
    return;

}

string multi(string st, int b)
{
    string ans;
    reverse(st.begin(), st.end());
    int c=0;
    for(int i=0;i<st.size();i++)
    {
        int x=(st[i]-'0')*b+c;
        c=x/10;
        ans.push_back(x%10+'0');
    }
    while(c!=0)
    {
        ans.push_back(c%10+'0');
        c=c/10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


string  cal(string st, int b, int p)
{
    for(int i=1;i<=p;i++)
    {
        st=multi(st, b);
    }
    return st;
}

int main()
{
//    cout<<multi("100", 1000)<<endl;
//    cout<<cal("10", 10000, 10000)<<endl;
    seive();
    int t, n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;

        map<int, int>mpans;
        map<int, int>::iterator it;
        while(n--)
        {
            map<int, int>mpcr;
            int x;
            cin>>x;
//            cout<<x<<endl;
            for(int i=0;p[i]*p[i]<=x;i++)
            {
//                cout<<"njg"<<endl;
                int cnt=0;
                while(x%p[i]==0)
                {
                    cnt++;
                    x=x/p[i];
//                    cout<<x<<"as"<<endl;
                }
                if(cnt)
                {
                    mpcr[p[i]]=cnt;
                    if(mpans[p[i]]!=0)
                    mpans[p[i]]=max(mpans[p[i]], mpcr[p[i]]);

                    else mpans[p[i]]=cnt;
                }

            }
//            cout<<x<<endl;
            if(x>1)
            {
                mpcr[x]=1;
//                cout<<x<<" "<<mpcr[x]<<endl;
                if(mpans[x]!=0)
                mpans[x]=max(1, mpans[x]);

                else mpans[x]=1;
            }
        }
        string ans="1";
        for(it=mpans.begin();it!=mpans.end();it++)
        {
//            cout<<it->first<<" "<<it->second<<endl;
            ans=cal(ans, it->first, it->second);
        }
        cout<<"Case "<<i<<": "<<ans<<endl;


    }

    return 0;
}
