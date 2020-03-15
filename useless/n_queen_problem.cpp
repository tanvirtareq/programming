#include<bits/stdc++.h>

using namespace std;

bool ar[1000][1000], chk;

int b;

bool can_be_place(int r, int c)
{
    for(int i=1;i<=b;i++)
    {
        if(ar[i][c]==1||ar[r][i]==1) return 0;

    }

    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=b;j++)
        {

            if(ar[i][j]==1&&i!=r&&j!=c&&((i+j)==(r+c)))
            {
                //cout<<"i+j"<<i+j<<endl;
                return 0;
            }
            if(ar[i][j]==1&&i!=r&&j!=c&&(i-j)==(r-c)) return 0;
        }

    }

    return 1;

}

void print()
{
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(ar[i][j]==1) cout<<"1";
            else cout<<"0";
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    return;
}

void place(int n)
{
    if(n==0)
    {
        print();
        chk=1;
        cout<<"solved"<<endl;
        return;
    }

    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(can_be_place(i, j))
            {
                ar[i][j]=1;
                cout<<"place  "<<i<<"  "<<j<<" position"<<endl;
                cout<<"have "<<n-1<<endl;
                print();
                cout<<endl<<endl;
                place(n-1);
                if(chk==1)
                {
                    return;
                }
                ar[i][j]=0;
                cout<<"uproot from "<<i<<" "<<j<<" position"<<endl;
                cout<<"have "<<n<<endl;
                print();
                cout<<endl;

            }

        }

    }


}

int main()
{
    freopen("n queen.txt", "w", stdout);
    cin>>b;
    place(b);

    return 0;
}
