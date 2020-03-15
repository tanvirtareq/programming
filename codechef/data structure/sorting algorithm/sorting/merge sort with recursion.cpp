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

void random_array_gene(int a[], int n, int x0, int b, int c, int m)
{
    a[0]=(x0*b+c)%m;
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

void merge_sort(int a[], int start, int end, int b[])
{
    int n=end-start+1;
    if(n==2)
    {

    }

}

int main()
{
    int a[100];

    random_array_gene(a,13, 11, 29, 19, 97);
    print(a, 13);

    return 0;
}
