#include<bits/stdc++.h>

using namespace std;

bool cmpr(pair<int, int> pr1,pair<int, int> pr2)
{
    int x1=pr1.first;
    int y1=pr1.second;
    int x2=pr2.first;
    int y2=pr2.second;

    if(x1<x2) return x1<x2;

    if(x1==x2) return y1>y2;

    return x1<x2;

}

int main()
{
    int t, n, xi, yi;
    vector<pair<int, int> >v;
    pair<int, int> pr;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        v.clear();
        while(n--)
        {
            scanf("%d%d", &xi, &yi);
            pr.first=xi;
            pr.second=yi;
            v.push_back(pr);

        }
        sort(v.begin(), v.end(), cmpr);
        n=v.size();
        for(int i=0;i<n;i++)
        {
            printf("%d %d\n", v[i].first, v[i].second);
        }



    }

    return 0;
}

