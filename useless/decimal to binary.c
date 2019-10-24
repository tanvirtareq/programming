 #include <stdio.h>
void fraction_decimal_2_binary(float x)
{

    int i, x1;

    printf(".");
    for(i=1;x!=0;i++)
    {
        x=x*2;

        x1=(int)x;
        printf("%d" , x1);
        x=x-x1;
    }
}

void int_decimal_2_binary(int x)
{
     int  n[100];
     int d, i;

     for(i=0;x!=0;i++)
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
    float x, x2;

    int x1;

    scanf("%f", &x);

    x1=(int)x;

    x2=x-x1;

    int_decimal_2_binary(x1);

    fraction_decimal_2_binary(x2);
}
