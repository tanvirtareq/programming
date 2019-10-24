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
typedef priority_queue<int, vector<int>, greater<int> > mnpqi;


pair<int, int> last[1000010];
pair<pair<int, int>, int>  first[1000010];
set<pair<int, int> > s;
string str;


int fy[]= {1, 0, -1, 0};
int fx[]= {0, 1, 0, -1};

void findEndPointFirstToi()
{
    int x=0, y=0, direct=0;

    int ct=0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='F')
        {
            x=x+fx[direct];
            y=y+fy[direct];

        }

        else if(str[i]=='R')
        {
            ct=(ct+1)%4;
            direct=(direct+1)%4;


        }

        else
        {
            ct=(ct+3)%4;
            direct=(direct+3)%4;
        }

        first[i]=make_pair(make_pair(x, y), ct);

    }

}

void findEndpointiToLast()
{
    int x=0, y=0;

    if(str[str.size()-1]=='F')
        y=1;

    last[str.size()-1]=make_pair(x, y);

    for(int i=str.size()-2; i>=0; i--)
    {
        if(str[i]=='F')
            y++;

        else if(str[i]=='R')
        {
            int x1=x;
            int y1=y;
            x=y1;
            y=-x1;
        }

        else if(str[i]=='L')
        {
            int x1=x;
            int y1=y;
            x=-y1;
            y=x1;
        }
        last[i]=make_pair(x, y);

    }
    return;

}

pair<int, int> balance(int x2,int y2, int ct)
{
    int bl=0;

    while(bl!=ct)
    {
        bl=(bl+1)%4;

        int x1=x2;
        int y1=y2;


        x2=y1;
        y2=-x1;

    }

    return make_pair(x2,  y2);

}

void trtAsR(int x1, int y1, pair<int, int>p)
{
    int x2=y1;
    int y2=-x1;


    s.insert(make_pair(p.first+x2, p.second+y2));
    cout<<p.first+x2<<" "<<p.second+y2<<endl;
    return;
}


void trtAsL(int x1, int y1, pair<int, int>p)
{
    int x2=-y1;
    int y2=x1;

    s.insert(make_pair(p.first+x2, p.second+y2));
    return;
}


void trtAsF(int x1, int y1, pair<int, int>p)
{
    int x2=x1;
    int y2=y1+1;

//    cout<<p.first+x2<<" "<<p.second+y2<<endl;

    s.insert(make_pair(p.first+x2, p.second+y2));
    return;
}

void showFirst()
{
    for(int i=0;i<str.size();i++)
    {
        cout<<first[i].first.first<<" "<<first[i].first.second<<" "<<first[i].second<<endl;

    }
    return ;

}


void showLast()
{
    for(int i=0;i<str.size();i++)
    {
        cout<<last[i].first<<" "<<last[i].second<<endl;

    }
    return ;

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin>>str;

    findEndpointiToLast();


    findEndPointFirstToi();
//
//        showFirst();
//        showLast();

    int x=last[1].first;
    int y=last[1].second;

//    cout<<x<<" "<<y<<endl;

    if(str[0]=='F')
    {

        s.insert(make_pair(y, -x));
        s.insert(make_pair(-y, x));

    }

    else if(str[0]=='R')
    {
        s.insert(make_pair(x,y+1));
        s.insert(make_pair(-y, x));

    }

    else if(str[0]=='L')
    {
        s.insert(make_pair(x,y+1));
        s.insert(make_pair(y, -x));

    }

    for(int i=1; i<str.size()-1; i++)
    {


        int x1=last[i+1].first;
        int y1=last[i+1].second;



        int x2=first[i-1].first.first;
        int y2=first[i-1].first.second;
        int ct=first[i-1].second;

        pair<int, int > p=balance(x2, y2, ct);

        cout<<p.first<<" "<<p.second<<endl;

        if(str[i]=='F')
        {
            trtAsR(x1, y1, p);
            trtAsL(x1, y1, p);

        }

        else if(str[i]=='R')
        {
            trtAsF(x1, y1, p);
            trtAsL(x1, y1, p);
        }

        else if(str[i]=='L')
        {
            trtAsR(x1, y1, p);
            trtAsF(x1, y1, p);

        }
    }
    x=first[str.size()-2].first.first;
    y=first[str.size()-2].first.second;

    if(str[str.size()-1]!='F'){

        int ct=first[str.size()-2].second;
        ct=(ct+4)%4;
        s.insert(make_pair(x+fx[ct], y+fy[ct]));
//        cout<<x<<" "<<y+1<<endl;
    }

    s.insert(make_pair(x, y));

//    cout<<x<<" "<<y<<endl;

    set<pair<int, int> > :: iterator it;

    for(it=s.begin();it!=s.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    cout<<s.size()<<endl;

    return 0;
}

/**

RRFRLFLFRFFLL


FRRFFRFLLFRF
18
FRFFFLLFRRRF
13
F
1
FF
3
FFF
5
FFFF
7
R
2
L
2
FR
3
FL
3
RF
3
LF
3
LR
3
FFR
5
FFL
5
FRF
4
FLF
4
FRR
4
FRL
4
FLR
4
FLL
4
RFF
5
RFR
5
RFL
5
RRF
4
RRL
4
RRR
4

*/

