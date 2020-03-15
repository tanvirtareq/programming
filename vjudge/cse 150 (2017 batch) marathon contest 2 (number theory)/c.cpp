#include<bits/stdc++.h>
#define sz 100

using namespace std;


int main()
{

   int t;
   scanf("%d", &t);
   for(int i=1;i<=t;i++)
   {
        int n, x=0;
        cin>>n;
        while(n--)
        {
            string st;
            cin>>st;
            for(int i=0;i<st.size();i++)
            {
                x=x+st[i]-'0';
            }


        }
        if(x%3==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;


   }

    return 0;
}


