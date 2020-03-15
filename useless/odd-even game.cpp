#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m, xn1, x01, xn2, x02, a,b;

//    time_t seconds;

//    seconds=time(NULL);

//    printf("time seconds=%d\n", seconds);

    printf("if odd then press 1\nif even press 0\n\nyour turn\n");

    srand(time(NULL));

    int cp=10000, yp=10000;


//    printf("%d",time(0));

    while(scanf("%d", &m))
    {
        if(m==0) break;
        int rnd=rand();

        a=rnd%2;

//        printf("random number = %d\n", rnd);

        if(a==0) puts("even");

        else puts("odd");

        printf("Judge decision!!\n");

        if(a!=m%2)
        {


            cp=cp-m;

            yp=yp+m;

            printf("wrong answer\n");

            printf("your point=%d\tcomputer's point=%d\n\n", yp, cp);

        }

        else{

            yp=yp-m;
            cp=cp+m;

            printf("right answer\n");

            printf("your point=%d\tcomputer's point=%d\n\n", yp, cp);

        }

        printf("computer's turn\nodd or even\n");

        a=rand();

        scanf("%d", &m);

//        printf("random number = %d\n", a);

        printf("computer kept %d\n", a);

        printf("Judge decision!!\n");

        if(a%2!=m)
        {

            yp=yp-a;
            cp=cp+a;

            printf("wrong answer\n");

            printf("your point=%d\tcomputer's point=%d\n\n", yp, cp);

        }

        else{

            yp=yp+a;
            cp=cp-a;

            printf("congratulations!!\nright answer\n");

            printf("your point=%d\tcomputer's point=%d\n\n", yp, cp);

        }

        printf("your turn\n");




//        printf("%d",rand() );





    }

    if(yp>cp)
    {
        printf("congratulations!!!\nyou won\nyour point=%d\tcomputer's point=%d\n", yp, cp);

    }

    else if(yp<cp) printf("you lost\nyour point=%d\tcomputer's point=%d\n", yp, cp);

    else printf("draw\nyour point=%d\tcomputer's point=%d\n", yp, cp);


    return 0;
}
