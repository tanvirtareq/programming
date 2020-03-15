#include<bits/stdc++.h>

using namespace std;

int main()
{

    int m, s;

//   int a[110];
//   int b[110];

    vector<int>b, a;

    cin>>m>>s;

    if(m*9<s) cout<<"-1 -1";

    else if(s<=0&&m!=1) cout<<"-1 -1";

    else
    {



    int ts=s;

    int i=0;
    int tm=m;
    while(ts>=10)
    {
//        a[tm]=9;
            a.push_back(9);
        tm--;
        ts=ts-9;
    }

    if(tm==1)
    {

        a.push_back(ts);
        ts=ts-ts;
    }

    else if(tm>1)
     {
////        a[1]=1;
//        ts=ts-1;

//        for(int i=2;i<tm;i++)
//            a[i]=0;

//        a[tm]=ts;
//        ts=ts-ts;

        while(tm--)
            a.push_back(0);

        a.push_back(1);
     }

     int tmn=m;

     int tss=s;
     while(tss>=10)
     {
         b.push_back(9);

         tmn--;
         tss=tss-9;


     }
    b.push_back(tss);

     tss=tss-tss;





     while(tmn>0)
     {
         i++;
         b.push_back(0);
         tmn--;

     }

     if(tm<0)
     {


        cout<<"-1 ";
     }

    else if(tm==0&&ts!=0) cout<<"-1 ";

    else
    {
        for(int j=m-1;j>=0;j--)
        {
            cout<<a[j];
        }
        cout<<" ";
    }

    if(tmn<0) cout<<"-1";

    else if(tmn==0&&tss!=0) cout<<"-1";

    else
    {
        for(int j=0;j<m;j++)
        cout<<b[j];

    }

    }
    return 0;
}
