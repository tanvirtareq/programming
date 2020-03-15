///define and macros are interpreted by preprocessor
#include<stdio.h>

#define increment(x) ++x

#define printseriese(f,y, z) for(f=1;f<=y;f=z+f) printf("%d", f)

#define multiply(a,b) a*b

#define merge(a, b) a##b

void macrop()
{
    char c='a';

    printf("%c", increment(c));

}

void macrop1()
{
    int i1=1, i2=10, i3=2;

    char sp;
    sp='d';

    printseriese(i1, i2, i3);
    sp='c';
    char c1='a', c2='z',c3=2;
    printseriese(c1,c2,c3);

}

void multiplymacros()
{
    printf("%d", multiply(2+3, 3+5));

}

void mergemacros()
{
    int x=12, y=34;

    printf("%d", merge(12,34));


}

#define sqr(x) x*x

/// using inline function
inline int square(int x){return x*x;}

void macros3()
{
    int x=36/sqr(6);/// it is interpreted x=36/6*6 . simplifying it x=6*6 then x=36
    /// 36/6*6!=36/(6*6)

    x=36/square(6);

    printf( "%d", x);

}

void interesing()
{
    printf("current file=%s\n",__FILE__);
    printf("current date=%s\n",__DATE__);
    printf("current time=%s\n",__TIME__);
}

int main()
{
    interesing();

    return 0;
}
