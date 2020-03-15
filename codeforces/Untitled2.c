#include<stdio.h>

void change(union p *x)
{
    (x.a)++;
    return;

}

union p{
int a;
char c;
};

int main()
{
    int a, b;
    a=5;
    union p x;
    x.a=98;

    change(x);
    printf("%d", a);
}
