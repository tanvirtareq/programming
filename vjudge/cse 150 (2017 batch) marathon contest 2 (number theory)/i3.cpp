#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, k;
    vector<long long int> v;
    vector<long long int> v1;

    scanf("%lld%lld", &n, &k);

    for(long long int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(i*i!=n)
            v1.push_back(n/i);
        }

    }

//    sort(v.begin(), v.end());

//cout<<v.size()

    if(v.size()>=k) printf("%lld", v[k-1]);

    else if(v.size()+v1.size()>=k)
    {
         k=k-v.size();
//         cout<<k<<endl;
        printf("%lld\n", v1[v1.size()-k]);
    }
    else  puts("-1");
    return 0;
}
