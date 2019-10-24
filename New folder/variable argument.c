#include<stdio.h>
#include<stdarg.h>

int sumf(int arg_numb,...)
{
    int sum=0;

    va_list va;

    va_start(va, arg_numb);

    int i;

    for(i=0;i<arg_numb;i++)
    {
//        sum+=va_arg(va, int);
        printf("%d  ", va_arg(va, int));
    }
    puts("");
    return sum;
}

int main()
{
    printf("%d", sumf(3, 1 ,2 ,3,4));

    return 0;
}
