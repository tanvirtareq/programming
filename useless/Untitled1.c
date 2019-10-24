#include<stdio.h>
int rec(int n)
{
	if(n==0) return 0;
	return rec(n-1)*rec(n);
}

int main()
{
	printf("%d",((1<<32)-1)>>100000000000000000000000000000000);
    return 0;
}
