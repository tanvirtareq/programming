#include<bits/stdc++.h>
typedef long long unsigned llu;



using namespace std;

int main()
{

    llu n, k, x=0;
    llu t;
//    cin>>n>>k;
    scanf("%llu%llu", &n, &k);

    for(llu i=1;i<=n;i++)
    {
//        cout<<" i "<<i<<endl;
        if(n%i==0)
        {
            x++;
//            cout<<x<<endl;
            if(x==k)
            {
//                cout<<i<<endl;
                    printf("%d\n", i);
                break;
            }
        }
    }
    if(x<k) puts("-1");


    return 0;

}
