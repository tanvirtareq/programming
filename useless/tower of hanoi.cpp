#include<stdio.h>

void hanoi(int n, char from, char to, char via)
{
    if(n>1)
    {
        hanoi(n-1, from, via, to);

        printf("move %d from %c to %c\n\n", n-1, from , via);

//        hanoi(n, from, to, via );

//        printf("move %d from %c to %c\n\n", n, from , to);

        hanoi(n-1, via, to, from);

//        printf("move %d from %c to %c\n\n", n-1, via , to);

    }

    return ;


}
int main()
{
    int n=3;

    hanoi(n, 'L', 'R', 'M');


    return 0;
}
