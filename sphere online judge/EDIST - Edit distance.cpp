#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

int table[2010][2010];


string a, b;

int ed(int i, int j)
{

    if(b[j]==0)
    {
      //  cout<<"________"<<endl;
        return a.size()-i;
    }
    if(a[i]==0)
    {
      //  cout<<"_______"<<endl;
        return b.size()-(j);
    }

    if(table[i][j]!=-1)
        return table[i][j];

    if(a[i]==b[j])
    {
    //    cout<<"______"<<endl;
        return ed(i+1, j+1);
    }

    int x=1+ed(i+1, j+1);
    int y=1+ed(i, j+1);
    int z=1+ed(i+1, j);
    int mx1=min(x, y);

   //     cout<<i<<" "<<j<<endl;
  //  cout<<a[i]<<" "<<b[j]<<endl;

  //  cout<<x<<" "<<y<<" "<<z<<endl;

    table[i][j]=min(mx1, z);
//
//    if(x>=z and x>=y)
//    {
//        cout<<a[i]<<" changed to "<<b[j]<<endl;
//    }
//
//    if(y>=z and y>=x)
//    {
//        cout<<"insert "<<b[j]<<endl;
//    }
//    else cout<<"remove "<<a[i]<<endl;

//cout<<"_______"<<endl;

    return table[i][j];
}

void show(int i,int j)
{

    if(b[j]==0)
    {
        return;
    }
    if(a[i]==0)
    {
        cout<<"insert ";
        for(int k=j;k<b.size();k++)
            cout<<b[k]<<" ";

        cout<<endl;
        return;
    }

    if(a[i]==b[i])
    {
        cout<<"don't change "<<a[i]<<endl;
        show(i+1, j+1);
        return;
    }

    int x=1+table[i+1][j+1];
    int y=1+table[i][j+1];
    int z=1+table[i+1][j];

    if(table[i][j]==x)
    {
        cout<<"replace "<<a[i]<<" into "<<b[j]<<endl;
        show(i+1, j+1);
    }

   else  if(table[i][j]==y)
    {
        cout<<"insert "<<b[j]<<endl;
        show(i, j+1);
    }

     else   if(table[i][j]==x)
    {
        cout<<"remove "<<a[i]<<endl;
        show(i+1, j);
    }

    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(table, -1, sizeof table);
        cin>>a>>b;

        printf("%d\n", ed(0, 0));

      //  show(0, 0);

    }


	return 0;
}





