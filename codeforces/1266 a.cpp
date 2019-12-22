#include<bits/stdc++.h>
#define ll long long
#define lu long long unsigned
#define dbg(a) cout<<#a<<" = "<<a<<endl
#define ii pair<int, int>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
//        cout<<s<<endl;

        int f1=0, f2=0;
        int ct=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0' and f1==0)
            {
                f1=1;
            }
            else if((int)(s[i]-'0')%2==0)
            {
                f2=1;
                ct=(ct+(int)(s[i]-'0'))%3;
            }
            else ct=(ct+(int)(s[i]-'0'))%3;
        }
//        cout<<ct<<endl;

        if(ct%3==0 and f1==1 and f2==1) cout<<"red"<<endl;
        else cout<<"cyan"<<endl;

    }


    return 0;
}
