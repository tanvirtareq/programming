#include<stdio.h>

void hanoi(int n, char from, char to, char via)
{
    if(n==0) return;
    hanoi(n-1, from, via, to);
    printf(" move %dth disk from %c to %c\n", n, from, to);
    hanoi(n-1, via, to, from);
    return;
}

int main()
{
    hanoi(4, 'a', 'c', 'b');

    return 0;
}
