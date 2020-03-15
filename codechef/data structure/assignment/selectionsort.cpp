#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

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
    for(int i=0;i<sz;i++)
        cout<<a[i]<<"   ";

    cout<<endl;
    return;
}



void selection_sort(int arr[],int n)
{
    int mid;
    for(int i=0;i<n;i++)
    {
        mid = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[mid])
            {
                mid = j;
            }
        }
        swap(arr[i],arr[mid]);
    }
}


int  inp(int a[])
{
    int n=0;
	while(cin>>a[n])
	{
		n++;
	}
    return n-1;
}


int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int a[100], b[100];

	random_array_gene(a, 10);

	print(a, 10);


	selection_sort(a,10);

	print(a, 10);




	return 0;
}



