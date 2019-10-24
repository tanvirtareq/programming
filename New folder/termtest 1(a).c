#include<stdio.h>
void TOHanoi(int x, int A, int B, int C)
{
    if(x<=0)
        return;
    TOHanoi(x-1,A,C,B);
    printf("Move disk %d from %c to %C\n", x, A, B);
    TOHanoi(x-2,C,B,A);

}

int main()
{
    int n;
    while(1==scanf("%d", &n))
    {
        TOHanoi(n, 'L', 'R', 'c');
    }
    return 0;

}
