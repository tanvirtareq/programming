#include<bits/stdc++.h>


using namespace std;

typedef long long int li;

int main()
{
    li n, x;

    vector<li> v;

    cin>>n;

    for(li i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);

    }

    sort(v.begin(), v.end());

    li s=0;

    for(li i=0;i<n/2;i++)
    {
//        s+=(ar[i]+ar[n-i+1])*(ar[i]+ar[n-i+1]);

        li y=v[i]+v[n-i-1];
        s+=y*y;

        //cout<<ar[i]<<" "<<ar[n-i+1]<<endl;
    }

    cout<<s<<endl;

    return 0;
}

/**

8 5
8 6 2 1 4 5 7 5
6 3 3 2 6 2 3 2
2 8
1 4
4 7
3 4
6 10


*/

