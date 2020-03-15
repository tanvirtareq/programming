#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        vector<int>v;
        int x;
        while(cin>>x){

            if(x==0){

            cout<<endl;
            break;
        }

        v.clear();
        v.push_back(x);
        for(int i=1;i<n;i++)
        {
            cin>>x;
            v.push_back(x);
        }

        int fl=1;
        int temp;
//        if(n%2==0) temp=n/2;
        temp=ceil((float)(n-1)/2);
        for(int i=0;i<temp;i++)
        {
           if(v[i]+v[n-1-i]!=n+1) fl=0;
           cout<<v[i]+v[n-1-i]<<endl;


        }

        if(fl==0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;


    }

    }
    return 0;
}
