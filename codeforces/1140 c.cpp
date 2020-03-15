#include<bits/stdc++.h>

using namespace std;

typedef long long unsigned li;

struct p{
li t, b, tb;

};

bool cmp(p a, p b)
{
    if(a.tb> b.tb) return true;

    return false;

}

int main()
{
    li  n, k;

    cin>>n>>k;

    vector<p> v;

    for( li i=0;i<n;i++)
    {
        p x;
        cin>>x.t>>x.b;
        x.tb=x.t*x.b;

        v.push_back(x);

    }

    sort(v.begin(), v.end(), cmp);

//    for(int i=0;i<n;i++)
//    {
//        cout<<v[i].tb<<endl;
//    }

    li mnb=v[0].b;

    li ans=v[0].tb;

    li mnt=v[0].t;

    for(int i=1;i<n;i++)
    {

        li tmp;

        mnb=min(mnb, v[i].b);

        mnt+=v[i].t;

        k--;

        if(ans<mnb*mnt)
        {
            ans=mnb*mnt;
        }



    }

    cout<<ans<<endl;

	return 0;
}


