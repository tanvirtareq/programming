#include<iostream>

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


void merge(int a[],int  l,int  x,int b[])
{
        int lb1=x, lb2=x+l, ub1=lb2-1, ub2=x+2*l-1;
        int lbb=x, ubb=ub2;
        while(lb1<=ub1&&lb2<=ub2)
        {
            if(a[lb1]<a[lb2])
            {
                b[x]=a[lb1];
                x++;
                lb1++;
            }
            else
            {
                b[x]=a[lb2];
                x++;
                lb2++;
            }
        }
        while(lb1<=ub1)
        {
            b[x]=a[lb1];
            x++;
            lb1++;
        }
        while(lb2<=ub2)
        {
            b[x]=a[lb2];
            x++;
            lb2++;
        }

}


void mergepass(int a[], int l, int sz, int b[])
{
    int q=(sz/(2*l))*2*l;
    if(l==8) cout<<q<<endl;
    int r=sz-q;
    for(int x=1;x<=q;x=x+2*l)
    {
        merge(a, l, x, b);
        cout<<"for l="<<l<<" x="<<x<<endl;
        print(b, x, x+2*l-1);
    }
    if(r>=2)
    {
        merge(a, r/2, q+1, b);
    }
    return;

}

void merge_sort(int a[], int sz)
{
    int l=1;
    int b[100];
    while(l<=sz)
    {
        mergepass(a, l, sz, b);
        l=2*l;
        mergepass(b, l, sz, a);
        l=2*l;
    }
    return;
}

int main()
{
    int a[11];

    random_array_gene(a, 9);

    print(a, 9);

    merge_sort(a, 9);
    print(a, 9);

    return 0;
}

