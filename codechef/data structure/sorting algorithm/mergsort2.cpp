#include<bits/stdc++.h>

using namespace std;

//int t1, t2;

void print(int x[],int f, int l)
{
    while(f<=l)
    {
        cout<<x[f]<<" ";
        f++;

    }
    cout<<endl;
    return;

}

void merg(int ar[], int f1, int l1, int l2, int br[])
{
    int f2=l1+1;
    int f=f1;
    while(f1<=l1||f2<=l2)
    {
        if(ar[f1]<=ar[f2])
        {
            br[f]=ar[f1];
            f++;
            f1++;
        }

        else
        {
            br[f]=ar[f2];
            f++;
            f2++;
        }

    }
    while(f1<=l1)
    {
        br[f]=ar[f1];
        f++;
        f1++;

    }

    while(f2<=l2)
    {
        br[f]=ar[f2];
        f++;
        f2++;

    }
    return;
}

void srt(int ar[],int f,int l, int br[])
{
    if(f==l) br[f]=ar[f];
   srt(ar, f, (f+l)/2, br);


   print(br, f, (f+1)/2);
   srt(ar, (f+1)/2+1, l, br);
    print(br, f, (f+1)/2);


    merg(ar, f, (f+1)/2, l, br);
    return;
}

void prnt(vector<int>x)
{
    for(int i=0;i<x.size();i++)
        cout<<x[i]<<" ";

    cout<<endl;
    return;

}



vector<int> merg(vector<int> v1, vector<int> v2)
{
    vector<int>x;
    int f1=0;
    int f2=0;
    while(f1<v1.size()&&f2<v2.size())
    {
        if(v1[f1]<v2[f2])
        {
            x.push_back(v1[f1]);
            f1++;
        }


        else
        {
            x.push_back(v2[f2]);
            f2++;
        }
    }

    while(f1<v1.size())
    {

            x.push_back(v1[f1]);
            f1++;
    }

    while(f2<v2.size())
    {

            x.push_back(v2[f2]);
            f2++;
    }
    return x;
}

vector<int> srt(vector<int> g, int f, int l, int t1)
{
    t1++;
    if(f==l)
    {
        vector<int>x;
        x.push_back(g[f]);
        return x;
    }
    vector<int>v1, v2, vm;
    v1=srt(g, f, (f+l)/2, t1);
    cout<<t1<<"'s  1st  ";
    prnt(v1);

    v2=srt(g, (f+l)/2+1, l, t1);
    cout<<t1<<"'s  2nd  ";
    prnt(v2);

    vm=merg(v1, v2);
    cout<<t1<<"'s  merg  ";
    prnt(vm);
    return vm;


}


int main()
{
//    t1=t2=0;
    int ar[10]={2, 5,1, 7,1 ,0, 8,1};
//    int ar[3]={2, 5,1};
    vector<int>v, x;
    v.assign(ar, ar+8);
    prnt(v);
    int br[10];

    x=srt(v, 0, 7, 0);
    prnt(x);

    return 0;
}
