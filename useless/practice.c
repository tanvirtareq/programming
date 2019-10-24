#include <stdio.h>

#include<ctype.h>

#include<string.h>

void string(char a1[100], char a2[100])
{
    char b[200];

    char c[300];

    int x;

//    x=strcmp(a1, a2);

//    printf("%d", x);

    strcpy(b , a1);

    printf("%s\n", b);
}

void ctype(char a)
{
    int x=isalpha(a);

    printf("%d\n", x);
    if(0!=isdigit(a))
    {
        printf("digit");
    }

    else if(0!=isalpha(a))
    {
        printf("alphabet\n");

        if(0!=islower(a))
        {
            printf("small");
        }
    }
}
void fraction_decimal_2_binary(float x)
{

    int i, x1;

    printf(".");
    for(i=1; x!=0; i++)
    {
        x=x*2;

        x1=(int)x;
        printf("%d", x1);
        x=x-x1;
    }
}

void int_decimal_2_binary(int x)
{
    int  n[100];
    int d, i;

    for(i=0; x!=0; i++)
    {
        n[i]=x%2;
        x=x/2;
    }

    i=i-1;

    while(i>=0)
    {
        printf("%d", n[i]);
        i=i-1;
    }

}


main()
{

    char a1[100], a2[100];

    scanf("%s", &a1);

    scanf("%s", a2);


//    char a;

//    a=getchar();
    string(a1, a2);
//    ctype(a);
//    float x, x2;

//    int x1;

//    scanf("%f", &x);

//    x1=(int)x;

//    x2=x-x1;

//    int_decimal_2_binary(x1);

//    fraction_decimal_2_binary(x2);
}
