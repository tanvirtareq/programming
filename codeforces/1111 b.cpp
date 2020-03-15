#include<bits/stdc++.h>
//#define m 10000007

typedef unsigned long long ull;
typedef long long int li;
//typedef vector<li> vli;


using namespace std;



int main() {

    li n, k, m;
    cin>>n>>k>>m;

    vector<li> pq;

    for(li i=1;i<=n;i++)
    {
        li x;
        cin>>x;
        pq.push_back(x);
    }

    sort(pq.begin(), pq.end());

    li r, s=0;

    if(n-1>= m)
    {
        r=n-m;

        for(li i=m;i<n;i++)
            s+=pq[i];


            double ans=(double) s/(double) r;

            cout<<fixed<<setprecision(20)<<ans<<endl;

            return 0;
    }

    else
    {
        r=1;
        s+=pq[n-1];

        double ans = (double)s+k;

          cout<<fixed<<setprecision(20)<<ans<<endl;

            return 0;
    }

    li rk=m-(n-r);

    for(int i=n-r;i<n;i++)
    s += min(k, rk);


    double ans=(double) s/(double) r;

    cout<<fixed<<setprecision(20)<<ans<<endl;

    return 0;
}

/**

5 4 4
1 1 1 1 1

5 4 4
1 1 1 1 5

*/



