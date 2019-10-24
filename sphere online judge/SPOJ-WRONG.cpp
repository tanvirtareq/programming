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

int n;
struct point
{
    int x,  y;
};

set<pair<int, int> >st;
string str;

void changeCommand(char cm, char *cm1, char *cm2)
{
    if(cm=='F')
    {
        *cm1='R';
        *cm2='L';
    }
    else if(cm=='R')
    {
        *cm1='F';
        *cm2='L';
    }

    else if(cm=='L')
    {
        *cm1='R';
        *cm2='F';
    }
    return;

}

point nex(point root, int direct)
{
    point nx=root;
    if(direct==1)
    {
        nx.y++;
        return nx;
    }
    if(direct==-1)
    {
        nx.y--;
        return nx;
    }
    if(direct==2)
    {
        nx.x++;
        return nx;
    }
    if(direct==-2)
    {
        nx.x--;
        return nx;
    }

}

int chanage2R(int direct)
{
    if(direct==1)
        return 2;
    if(direct==-1)
        return -2;
    if(direct==2)
        return -1;
    if(direct==-2)
        return 1;

}

int chanage2L(int direct)
{
    if(direct==1)
        return -2;
    if(direct==-1)
        return 2;
    if(direct==2)
        return 1;
    if(direct==-2)
        return -1;

}

pair<point, int> change(point root, char command, int direcc)
{
    if(command=='F')
    {
        point nx=nex(root, direcc);

        return make_pair(nx, direcc);

    }

    if(command=='R')
    {
        int dir=chanage2R(direcc);

        return make_pair(root, dir);

    }

    if(command=='L')
    {
        int dir=chanage2L(direcc);

        return make_pair(root, dir);

    }

}


void dfs(point root, int pos, int direc, bool isChanged)
{
    if(pos>=n)
    {

        if(isChanged==true)
        {
//            cout<<root.x<<" "<<root.y<<endl;
            st.insert(make_pair(root.x, root.y));
        }
        return;
    }


    pair<point, int> p=change(root, str[pos], direc);

    dfs(p.first, pos+1,  p.second, isChanged);


    if(isChanged==false)
    {
        char cmnd1, cmnd2;

        changeCommand(str[pos], &cmnd1, &cmnd2);

        point nx=nex(root, direc);
        p=change(root, cmnd1, direc);

        dfs(p.first, pos+1, p.second, true);

        p=change(root, cmnd2, direc);

        dfs(p.first, pos+1, p.second, true);

    }


    return;

}

void findEndPoint(point root, int pos, int direct)
{
    if(pos>=n)
    {
//        cout<<root.x<<" "<<root.y<<endl;

        return;
    }


    pair<point, int> p=change(root, str[pos], direct);

    findEndPoint(p.first, pos+1,  p.second);

    return;


}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        st.clear();

        cin>>str;


        n=str.size();
        point r;
        r.x=0;
        r.y=0;

//        findEndPoint(r, 0, 1);


        dfs(r, 0, 1, false);

        cout<<st.size()<<endl;
    }
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
