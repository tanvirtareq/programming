#include<bits/stdc++.h>

using namespace std;

typedef long long int li;


int main()
{

    li n, m, tp, p, q, x;

    scanf("%d%d", &n, &m);

    vector<pair<int, int> > v; /// p, typ

    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &tp, &p);

        v.push_back(make_pair(p, tp));

    }

    sort(v.begin(), v.end());

    scanf("%d", &q);

    li cumsum[110010];

    cumsum[0]=v[0].first;

    map<int, vector<pair<int, li> > > mp;  /// [typ] pos, p

    mp[v[0].second].push_back(make_pair(0, v[0].first));

    for(int i=1;i<n;i++)
    {
        cumsum[i]=cumsum[i-1]+v[i].first;


        mp[v[i].second].push_back(make_pair(i, v[i].first));
    }

//    cout<<"yes"<<endl;


    while(q--)
    {
            scanf("%d%d", &x, &tp);
            x--;
            int i=0;

            int s=0;

            int tr=0;

            int y=x;

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
            printf("%lld\n", cumsum[x]-mps);

//            else cout<<"-1"<<endl;

            else printf("-1\n");
    }

	return 0;
}


