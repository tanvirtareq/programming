#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;


bool cmptr(pair<int, string> p, pair<int, string> q)
{
    if(p.first>q.first) return true;
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int, string> > p;

    for(int i=0;i<n;i++)
    {
        int x;
        string str;
        cin>>str>>x;
        p.push_back(make_pair(x, str));

    }
    sort(p.begin(), p.end(), cmptr);

//    for(int i=0;i<n;i++)
//    {
//        cout<<p[i].second<<" "<<p[i].first<<endl;
//    }
//    reverse(p.begin(), p.end());

    int vis[n];
    memset(vis, 0, sizeof vis);

    int as[n];
    int j;

    for(int i=0;i<n;i++)
    {

        j=p[i].first;
//        cout<<p[i].second<<" "<<j<<endl;
        if(vis[j]==0)
        {
            vis[j]=1;
            as[j]=i;
//            cout<<j<<" "<<p[as[j]].second<<endl;
        }
        else
        {
            j++;
            while(j<n)
            {
                if(vis[j]==0)
                {
                    vis[j]=1;
                    as[j]=i;
//                    cout<<j<<" "<<p[as[j]].second<<endl;
                    break;
                }
                else
                {
                    j++;
                }
            }

            if(j>=n)
            {
                cout<<-1<<endl;
                return 0;
            }
        }

    }
    int ans[n];

//    for(int i=0;i<n;i++)
//    {
//        cout<<p[as[i]].first<<" "<<p[as[i]].second<<endl;
//    }

    for(int i=0;i<n;i++)
    {
        int dif=i-p[as[i]].first;
        if(dif<0) dif=0;

        cout<<p[as[i]].second<<" "<<5000+dif-i<<endl;
        ans[i]=dif-i;

//        cout<<p[as[i]].second<<" "<<ans[i]<<endl;;

    }



	return 0;
}



