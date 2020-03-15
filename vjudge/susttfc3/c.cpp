
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


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    li vp,vd, t, f, c;

    cin>>vp>>vd>>t>>f>>c;

    if(vd<vp){
        cout<<0<<endl;
        return 0;
    }

    if(vd<=vp and t>0)
    {
        cout<<0<<endl;
        return 0;
    }

    if(vd<=vp and t==0)
    {
        cout<<1<<endl;
        return 0;
    }

    double distFor1stMeet=(double)(t*vp*vd)/((double)(vd-vp));
//    cout<<distFor1stMeet<<endl;

    if(distFor1stMeet>=c)
    {
        cout<<0<<endl;
        return 0;
    }

    int x=1;

    double dForprevMeet=distFor1stMeet;
    double dForNextMeet;

    while(1)
    {
        dForNextMeet=f+dForprevMeet*((double)(vp+vd)/((double)vp*vd));
//        cout<<dForNextMeet<<endl;
        dForNextMeet=dForNextMeet/((double)(vd-vp)/((double)(vd*vp)));
//        cout<<dForNextMeet<<endl;

        if(dForNextMeet>=c)
        {
            cout<<x<<endl;
            return 0;
        }
        else{
         dForprevMeet=dForNextMeet;
                x++;
        }

    }



	return 0;
}

