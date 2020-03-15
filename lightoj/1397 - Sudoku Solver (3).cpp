#include<bits/stdc++.h>

using namespace std;

int a[10][10], row[10][10], col[10][10], p[10][10];

bool prun[10][10][10];

void makeNotPossible(int r, int c, int v)
{
    cout<<"make not possible "<<r<<" "<<c<<" to "<<v<<endl;

    prun[r][c][v]=1;
    return;

}


int wp(int i, int j)
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

bool possible(int r, int c, int v)
{
    if(prun[r][c][v]==1){
     cout<<" not possible in "<<r<<" "<<c<<" to "<<v<<endl;
//            return 0;
    }
    if(row[r][v]==0 and col[c][v]==0 and p[wp(r, c)][v]==0) return 1;

    return 0;
}

void show()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

}


int  place(int x, int r)
{

//    cout<<x<<" "<<r<<endl;
    if(x==10) return 1;

    if(r==10)
    {
        if(place(x+1, 1)) return 1;

        else return 0;
    }

//    if(r==1 and x==2) cout<<row[r][x]<<endl;

    if(row[r][x]==1)
    {
       return  place(x, r+1);
    }

    for(int i=1;i<=9;i++)
    {
        if(r==5 and i==i and x==2 ) cout<<i<<" "<<a[r][i]<<endl;

        if(a[r][i]==0 and possible(r, i, x))
        {
            st(r, i, x);

            show();

            if(place(x, r+1)  ) return 1;


            rmv(r, i, x);

            makeNotPossible(r, i, x);


        }

    }

    return 0;



}


int main()
{

    cout<<pow(81, 81)<<endl;

    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        memset(a, 0, sizeof a);
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(p, 0, sizeof p);
        memset(prun, 0, sizeof prun);

        cin.ignore();

        string str[10];
        cin>>str[1]>>str[2]>>str[3]>>str[4]>>str[5];
        cin>>str[6]>>str[7]>>str[8]>>str[9];

//        cout<<str[1]<<endl;

//        show();

        for(int j=1;j<=9;j++)
            for(int k=0;k<9;k++)
        {

            if(str[j][k]=='.') st(j, k+1, 0 );
            else
            st(j, k+1, str[j][k]-'0');
        }

//        show();


        place(1, 1);

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
