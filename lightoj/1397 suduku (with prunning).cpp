#include<bits/stdc++.h>

using namespace std;

int a[10][10], row[10][10], col[10][10], p[10][10];
int number[10], rowcount[10], completed, n;

vector<pair<int, int> >vn;
vector<pair<int, int> >rcn;

int inline wp(int i, int j)
{
    if((i<=3) and (j<=3)) return 1;

    if((i<=6) and (j<=3)) return 2;

    if((i<=9) and (j<=3)) return 3;

    if((i<=3) and (j<=6) ) return 4;
    if((i<=6) and (j<=6) ) return 5;
    if((i<=9) and (j<=6) ) return 6;
    if((i<=3) and (j<=9) ) return 7;
    if((i<=6) and (j<=9) ) return 8;
    if((i<=9) and (j<=9) ) return 9;

}

void inline st(int r, int c, int v)
{
    row[r][v]=1;
    col[c][v]=1;

    p[wp(r, c)][v]=1;

    a[r][c]=v;

    return ;
}

void inline rmv(int r, int c, int v)
{
    row[r][v]=0;
    col[c][v]=0;

    p[wp(r, c)][v]=0;

    a[r][c]=0;

    return ;
}

bool inline  possible(int r, int c, int v)
{
    if(row[r][v]==0 and col[c][v]==0 and p[wp(r, c)][v]==0) return 1;

    return 0;
}

void inline show()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cout<<a[i][j];
//            printf("%d", a[i][j]);
        }
        cout<<endl;
//        puts("");
    }
//    cout<<endl;

}


int inline place(int x, int r)
{

//    cout<<x<<" "<<r<<endl;
    if(x==9){
            completed=0;
            return 1;
    }

    if(r==9)
    {
        if(place(x+1, 0)) return 1;

        else return 0;
    }

//    if(r==1 and x==2) cout<<row[r][x]<<endl;

    if(row[rcn[r].second][vn[x].second]==1)
    {
       return  place(x, r+1);
    }

    for(int i=1;i<=9;i++)
    {
//        if(r==1 and i==2 and x==2 ) cout<<"fc"<<endl;

        if(a[rcn[r].second][i]==0 and possible(rcn[r].second, i, vn[x].second))
        {
            st(rcn[r].second, i, vn[x].second);

//            show();

            if(place(x, r+1)  ) return 1;


            rmv(rcn[r].second, i, vn[x].second);


        }

    }

    return 0;



}

bool cmp(pair<int, int> p, pair<int, int> q)
{
    if(p.second<=q.second) return true;

    else return false;

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin>>t;
//    scanf("%d", &t);

    for(int i=1;i<=t;i++)
    {
        memset(a, 0, sizeof a);
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(p, 0, sizeof p);
        memset(number, 0, sizeof number);
        memset(rowcount, 0, sizeof rowcount);

        vn.clear();
        rcn.clear();

        completed=0;

        cin.ignore();
//            scanf("%*c");

        string str[10];
        cin>>str[1]>>str[2]>>str[3]>>str[4]>>str[5];
        cin>>str[6]>>str[7]>>str[8]>>str[9];

//        cout<<str[1]<<endl;

//        show();

        for(int j=1;j<=9;j++)
            for(int k=0;k<9;k++)
        {

            if(str[j][k]=='.') st(j, k+1, 0 );
            else{
            st(j, k+1, str[j][k]-'0');

            number[a[j][k+1]]++;

            rowcount[j]++;
            }


        }

        for(int j=1;j<=9;j++)
        {
            vn.push_back(make_pair(number[j], j));
            rcn.push_back(make_pair(rowcount[j], j));
        }

        sort(vn.begin(), vn.end());
        sort(rcn.begin(), rcn.end());
//        sort(rowcount+1, rowcount+10);



//        show();

            place(0, 0);

        cout<<"Case "<<i<<":"<<endl;
        show();


    }

}

/**


3

****
2341
4123
3214

*243
*312
*421
*134

*41*
**3*
2*41
4*2*

*/


