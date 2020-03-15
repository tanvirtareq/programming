#include<bits/stdc++.h>

using namespace std;

int a[5][5], row[5][5], col[5][5], p[5][5];

void show()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

}

int wp(int i, int j)
{
    if((i==1 or i==2) and (j==1 or j==2)) return 1;

    if((i==1 or i==2) and (j==3 or j==4)) return 2;

    if((i==3 or i==4) and (j==1 or j==2)) return 3;

    if((i==3 or i==4) and (j==3 or j==4) ) return 4;

}

void inline st(int i, int j, int v)
{
    row[j][v]=1;
    col[i][v]=1;

    p[wp(i, j)][v]=1;

    a[i][j]=v;

    return ;
}

void inline rmv(int i, int j, int v)
{
    row[j][v]=0;
    col[i][v]=0;

    p[wp(i, j)][v]=0;

    a[i][j]=0;

    return ;
}

bool possible(int r, int c, int v)
{
    if(row[r][v]==0 and col[c][v]==0 and p[wp(r, c)][v]==0) return 1;

    return 0;
}

int  place(int x, int r)
{
//    show();

    if(x==5) return 1;

    if(r==5)
    {

        show();
        if(place(x+1, 1)) return 1;

        else return 0;
    }

    if(row[r][x]==1)
    {
       return  place(x, r+1);
    }

    for(int i=1;i<=4;i++)
    {
        if(a[r][i]==0 and possible(r, i, x))
        {
            st(r, i, x);

            show();

            if(place(x, r+1)  and place(x+1, 1)) return 1;

            else
            {
                rmv(r, i, x);
            }


        }

    }

    return 0;



}



int main()
{

    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        cin.ignore();

        string str[5];
        cin>>str[1]>>str[2]>>str[3]>>str[4];

//        cout<<str[1]<<endl;

//        show();

        for(int j=1;j<=4;j++)
            for(int k=0;k<4;k++)
        {

            if(str[j][k]=='*') st(j, k+1, 0 );
            else
            st(j, k+1, str[j][k]-'0');
        }

//        show();


            place(1, 1);

        cout<<"Case #"<<i<<":"<<endl;
        show();


    }

}

/**


3

****
2341
4123
3214


*/
