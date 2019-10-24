#include<bits/stdc++.h>

using namespace std;

void random_array_gene(int a[], int n)
{
    int  b=19, c=13, m=100;
    a[0]=(11*b+c)%m;
    for(int i=1;i<=n;i++)
    {
        a[i]=(a[i-1]*b+c)%m;
    }
    return;
}

void print(int a[], int sz)
{
    for(int i=1;i<=sz;i++)
        cout<<a[i]<<"   ";

    cout<<endl;
    return;
}

void print(int a[], int start, int en)
{
    for(int i=start;i<=en;i++)
        cout<<a[i]<<"   ";

    cout<<endl;
    return;
}

void merge(int a[], int lb1,int  ub1,int lb2,int ub2,int  b[])
{
    int na=lb1, nb=lb2, nc=lb1, ub3=ub2;
    while(na<=ub1&&nb<=ub2)
    {
        if(a[na]<a[nb])
        {
            b[nc]=a[na];
            na++;
            nc++;
        }
        else
        {
            b[nc]=a[nb];
            nb++;
            nc++;
        }
    }

    while(na<=ub1)
    {
        b[nc]=a[na];
        na++;
        nc++;
    }
    while(nb<=ub2)
    {
        b[nc]=a[nb];
        nb++;
        nc++;
    }
    return;
}

void merge_pass(int a[], int sz, int l, int b[])
{
    int p=sz/(2*l);
    cout<<"p= "<<p<<endl;
    int q=p*2*l;
    cout<<"q="<<q<<endl;
    int r=sz-q;
    cout<<"r="<<r<<endl;

    for(int x=1;x<=q;x=x+2*l)
    {
        merge(a, x, x+l-1, x+l, x+l+l-1, b);

    }
    if(r<=l)
    {
        for(int i=q+1;i<=sz;i++)
            b[i]=a[i];
    }
    else
    {
        merge(a, q, q+l-1, q+l, sz, b);
    }
    return;
}

void merge_sort(int a[],int sz)
{
    for(int l=1;l<=sz;l=2*l)
    {
        int b[100];
        merge_pass(a, sz, l, b);
        print(b, sz);
        l=2*l;
        merge_pass(b, sz, l, a);
        print(a, sz);
    }
    return;
}

int main()
{
    int a[100]={0, 66, 33, 40, 22, 55, 88, 60, 11, 80, 20, 50, 44, 77, 30};
//    random_array_gene(a, 10);

    print(a, 14);

    merge_sort(a, 14);
    print(a, 14);

    return 0;
}

