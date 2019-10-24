#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
typedef long long int lld;

using namespace std;

int ar[10]={1, 6, 2, 4, 9, 4,0, 1, 5 ,11};

void show()
{
    for(int i=0;i<10;i++)
        cout<<ar[i]<<" ";

        cout<<endl;

        return;

}

void quicksort(int lb, int ub)
{
    if(lb>=ub) return;

    int low=lb, high=ub, right=1;

    while(low<high)
    {
        if(ar[low]>ar[high])
        {
            swap(ar[low], ar[high]);
            right^=1;

        }

        right? high--:low++;

    }

    show();

    quicksort(lb, low-1);
    quicksort(low+1, ub);

    return;
}

int main()
{
    show();
    quicksort(0 , 9);
    for(int i=0;i<10;i++)
        cout<<ar[i]<<endl;

	return 0;
}

