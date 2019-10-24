#include<bits/stdc++.h>

using namespace std;


int board[100][100], c;
bool chk;

void printr(bool *a, int sz)
{
    for(int i=1;i<=sz;i++)
    {
        cout<<a[i]<<" "<<i<<endl;
    }
    cout<<endl;
}

void print( int b)
{
    cout<<c++<<endl;
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=b;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<endl<<endl;
}

bool is_attack(bool collc[], bool diag1[], bool diag2[],int i,int d1, int d2)
{
    if(collc[i]||diag1[d1]||diag2[d2]) return 1;

    else return 0;
}

void place(int s, int b,bool collc[],bool diag1[], bool diag2[])
{
    if(s==b+1)
    {
        cout<<"solved"<<endl;
        print( b);
        chk=1;
        return;
    }

    for(int i=1;i<=b;i++)
    {
        if(!is_attack(collc, diag1, diag2, i,b+(s-i),s+(i-1)))
        {
            collc[i]=1;
            diag1[b+(s-i)]=1;
            diag2[s+(i-1)]=1;
            board[s][i]=1;
            cout<<"place "<<s<<" "<<i<<"position"<<endl;
            print(b);
            place(s+1, b, collc, diag1, diag2);
            if(chk==1) return;

            collc[i]=0;
            diag1[b+(s-i)]=0;
            diag2[s+(i-1)]=0;
            board[s][i]=0;
            cout<<"uproot from "<<s<<" "<<i<<endl;
            print(b);
        }
    }

    return;
}

bool placed(int r, int b,bool collc[],bool diag1[],bool diag2[])
{
    for(c==1;c<=b;c++)
    {
        int d1=b+(r-c) , d2=r+(c-1);
        if(!is_attack(collc, diag1, diag2, c, d1, d2))
        {
            collc[c]=1;
            diag1[b+(r-c)]=1;
            diag2[r+(c-1)]=1;
            board[r][c]=1;
            return 1;
        }
    }
    return 0;
}

void uproot(int r,bool collc[], bool diag1[],bool diag2[], int c, int d1, int d2)
{

        collc[c]=0;
        diag1[d1]=0;
        diag2[d2]=0;
        board[r][c]=0;
        return;
}

void itr(int b, bool collc[], bool diag1[], bool diag2[])
{
    for(int i=1;i<=b;i++)
    {
        bool x=placed(i, b, collc, diag1, diag2);
        if(x==0)
        {
            uproot(i-1);
            i=i-2;
            continue;
        }
    }
}

int main()
{
    int b;
    cin>>b;
//        freopen("17 queen prob2.txt","w", stdout);
        bool rowc[b+1], collc[b+1], diag1[2*b+1], diag2[2*b+1];
        memset(rowc, 0, (b+1)*sizeof(bool));
        memset(collc, 0, (b+1)*sizeof(bool));
        memset(diag1, 0, (2*b+1)*sizeof(bool));
        memset(diag2, 0, (2*b+1)*sizeof(bool));
        chk=0;
        memset(board, 0, 100*100*sizeof(int));
        print(b);
//        place(1, b, collc, diag1, diag2);
        itr(b);

    return 0;
}

