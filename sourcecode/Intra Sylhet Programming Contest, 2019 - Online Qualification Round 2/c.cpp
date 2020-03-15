#include<bits/stdc++.h>

using namespace std;

typedef long long int li;


int main()
{

    li n, m, tp, p, q, x;

    scanf("%lld%lld", &n, &m);

    vector<pair<li, li> > v; /// p, typ

    for(li i=0;i<n;i++)
    {
        scanf("%lld%lld", &tp, &p);

        v.push_back(make_pair(p, tp));

    }

    sort(v.begin(), v.end());

    scanf("%lld", &q);

    li cumsum[110010];

    cumsum[0]=v[0].first;

    map<li, vector<pair<li, li> > > mp;  /// [typ] pos, p

    mp[v[0].second].push_back(make_pair(0, v[0].first));

    for(li i=1;i<n;i++)
    {
        cumsum[i]=cumsum[i-1]+v[i].first;


        mp[v[i].second].push_back(make_pair(i, v[i].first));
    }

//    cout<<"yes"<<endl;


    while(q--)
    {
            scanf("%lld%lld", &x, &tp);
            x--;
            li i=0;

            li s=0;

            li tr=0;

            li y=x;

            li mps=0;

//            s=cumsum[x-1];

            for(;i<mp[tp].size();i++)
            {
                if(mp[tp][i].first>(x))
                {
                    break;
                }

                else
                {
//                    s-=mp[tp][i].second;

                       mps+=mp[tp][i].second;
                        tr++;
                }

            }



//            cout<<"yes"<<endl;

            while((x-tr)!=y)
            {
                x++;

                if(i<mp[tp].size()  and mp[tp][i].first<=(x))
                {

                    mps+=mp[tp][i].second;
                    tr++;
                    i++;

                }

            }

            if(x<n)
            cout<<cumsum[x]-mps<<endl;

            else cout<<"-1"<<endl;

    }

//    while(q--)
//    {
//        scanf("%d%d", &x, &tp);
//        int i=0;
//
//        li s=0;
//
//        while(x>0 and i<v.size())
//        {
//            if(v[i].second!=tp){
//                    x--;
//             s+=v[i].first;
//            }
//
//            i++;
//        }
//
//        if(x==0) printf("%lld\n", s);
//
//        else printf("-1\n");
//
//    }

	return 0;
}

