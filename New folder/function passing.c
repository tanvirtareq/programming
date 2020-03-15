#include<stdio.h>

int process(int (*f)(int ,int), int a, int b)
{
    return f(a, b);


}

int add(a, b)
{

    return a+b;
}

int sub(a, b)
{
    return a-b;
}

int main()
{
    int a, b;
    char op;
    scanf("%d%c%d", &a,&op, &b);
    if(op=='+') printf("%d" ,process(add, a, b));
    if(op=='-') printf("%d", process(sub, a, b));

    return 0;
}
