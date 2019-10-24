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
    for(int i=1;i<=sz;i++)
        cout<<a[i]<<"   ";

    cout<<endl;
    return;
}

void bubble_sort(int arr[],int n)
{
    for(int i=n;i>0;i--)
    {
        for(int j=2;j<=i;j++)
        {
           // cout<<arr[j]<<"  "<<arr[j-1]<<endl;
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);
               // print(arr, n);
        }
       // print(arr, n);
    }
}
int  inp(int a[])
{
    int n=1;
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


	bubble_sort(a,10);

	print(a, 10);




	return 0;
}

