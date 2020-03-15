 #include <stdio.h>
main()
{
    float x;

    int i, x1;

    scanf("%f", &x);

    printf("0.");
    for(i=1;x!=0;i++)
    {
        x=x*2;

        x1=(int)x;
        printf("%d" , x1);
        x=x-x1;
    }
}
