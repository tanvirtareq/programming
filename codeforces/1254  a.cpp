#include<bits/stdc++.h>
using namespace std;
int r, c, k, q, ar[200][200], br[200][200];
char ch, cr[200][200];
int main()
{
    cin>>q;
    while(q--)
    {
        cin>>r>>c>>k;
        int ct=0;
        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
            {
                cin>>ch;
                ct+=ar[i][j]=(ch=='R');
            }

        int i=1,id=1, j=1,ft=0, f=0, flg=0,tk=ct/k, xtra=ct%k;
        br[1][1]=id;
        if(ar[1][1]==1)
        {
            flg=1;
        }

        while(1)
        {
//            cout<<i<<" "<<j<<endl;
            if(!f)
            {
                if(j==c)
                {
                    if(i==r)
                        break;
                    i++;
                    f=1;
                }
                else
                    j++;
            }
            else
            {

                if(j==1)
                {
                    if(i==r)
                        break;
                    i++;
                    f=0;
                }
                else
                    j--;

            }


            if(ar[i][j]==1 and flg==1)
            {
                if(xtra)
                    ft=(ft+1)%(tk+1);
                else
                    ft=(ft+1)%tk;
                if(ft==0)
                    xtra=max(0, xtra-1), id++;
            }
            if(ar[i][j]==1 and flg==0) flg=1;

             br[i][j]=id;
        }

        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                int k=br[i][j];
                if(k>52)
                    cr[i][j]='0'+(k-53);
                else if(k>26)
                    cr[i][j]='a'+(k-27);
                else if(k>0)
                    cr[i][j]='A'+(k-1);

                cout<<cr[i][j];
            }

            cout<<endl;
        }
    }

    return 0;
}
