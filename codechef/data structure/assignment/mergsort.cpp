#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

void bubble_sort(int arr[],int n)
{
    for(int i=n-1;i>0;i--)
    {
        for(int j=1;j<i;j++)
        {
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);
        }
    }
}
void insertion_sort(int arr[],int n)
{
    int tmp,j;
    for(int i=1;i<n;i++)
    {
        tmp = arr[i];
        j=i-1;
        while((j>-1) && (tmp < arr[j]))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
    }
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

void merg(int lba, int lbb,int ubb,int a[], int b[] )
{

	int uba=lbb-1;
	int lbc=lba, ubc=ubb;
	while(lba<=uba&&lbb<=ubb)
	{
		if(a[lba]<=a[lbb])
		{
			b[lbc]=a[lba];
			lba++;
		}
		else
		{
			b[lbc]=a[lbb];
			lbb++;
		}
		lbc++;
	}


	while(lba<=uba)
	{
		b[lbc]=a[lba];
		lba++;
		lbc++;
	}
	while(lbb<=ubb)
	{
		b[lbc]=a[lbb];
		lbb++;
		lbc++;
	}

	return;

}

void mergpass(int a[], int b[], int n, int l)
{
	int tpair=n/(2*l);
	int remains=n-tpair*2*l;

	for(int i=1;i<=tpair;i++)
	{

		int lb=1+(i-1)*2*l;
		merg(lb, lb+l, lb+2*l-1, a, b);
	}

	if(remains<=l)
	{
		for(int i=n-remains+1;i<=n;i++)
		{
			b[i]=a[i];
		}
	}
	else
	{
		merg(tpair*2*l+1, tpair*2*l+l+1, n, a, b);
	}
	return;
}

void mergsort(int a[],int b[], int n)
{
	int l=1;
	while(l<n)
	{
		mergpass(a, b, n, l);
		print(b, n);
		l=l*2;
		mergpass(b, a, n, l);
		print(a, n);
		l=l*2;
	}
	return;

}

int  inp(int a[])
{
    int n=0;
	while(cin>>a[n])
	{
		n++;
		cout<<a[n-1]<<endl;
	}
    return n;
}


int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a[100], b[100];

	int n=inp(a);

	print(a, n);


	bubble_sort(a, n);

	print(a, n);




	return 0;
}
