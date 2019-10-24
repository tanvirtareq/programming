#include<bits/stdc++.h>

using namespace std;

void print_1_to_n(int n)
{
    if(n==0) return;

    print_1_to_n(n-1);
    cout<<n<<endl;
    return;

}

void print_n_to_1(int n)
{
    if(n==0) return;
    cout<<n<<endl;

    print_n_to_1(n-1);
    return;
}

void p2(int ar[],int n, int k)
{
    if(n==k/2) return;

    cout<<ar[k-n]<<" "<<ar[n-1]<<endl;

    p2(ar, n-1, k);
    return;

}

int main()
{
    int ar[7]={1,2,3,4,5,6,7};
    int n=7;

    p2(ar, n, n);

    return 0;
}
