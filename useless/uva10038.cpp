#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while(scanf("%d", &n)!=EOF)
    {
        vector<int> a, b;

        int t=n;

        int j=1;

        while(t--)

        {
            b.push_back(j);
            j++;

            int temp;

            cin>>temp;

            a.push_back(temp);



        }

        int flug=0;
        for(int i=0;i<n-1;i++)
        {
            int c=abs(a[i]-a[i+1]);

            if(b[c]!=0&&c<n) b[c]=0;

            else flug =1;


        }

        if(flug==1) cout<<"Not jolly"<<endl;

        else cout<<"Jolly"<<endl;



    }



    return 0;
}
