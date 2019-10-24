#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for(int i=1;i<=t;i++)
    {
        int n, d, mx=0;
        set<int> s;
        set<int> ::iterator it;

        scanf("%d%d", &n, &d);

        cout<<n<<endl;

        int ar[n+10];

        for(int j=1;j<=n;j++)
        {
//            int x;
            scanf("%d", &ar[j]);
            s.insert(ar[j]);
            cout<<ar[j]<<endl;
            if(j==46)
                cout<<s.size()<<" asd"<<endl;

            if(s.size()==d)
            {
//                if(j==46)
                cout<<"yes "<<j<<endl;
                it=s.end();
                it--;
//                cout<<*it<<endl;

                int dif=*it-*s.begin();

                cout<<j<<" "<<j-d+1<<" "<<dif<<endl;
                mx=max(mx, dif);
                s.erase(ar[j-d+1]);

                cout<<s.size()<<" f"<<endl;

            }

        }

        printf("Case %d: %d\n", i , mx);

    }

    return 0;
}

/**
1
46 8
90 55 122 65 124 3 112 86 58 46 59 74 14 87 116 103 13 6 1 26 116 82 98 112 117 16 55 55 40 60 123 2 115 117 67 111 120 51 70 51 98 1 125 112 88 113

*/
