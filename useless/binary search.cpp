#include<stdio.h>

int main()
{

    int a[8]={2, 5,7,9,12,12, 12,23};

    int k=23, i;

    int b=0;

    int e=7;



    while(b<=e)
    {
        int m=(b+e)/2;

           printf("m=%d\n", m);



        if(a[m]==k)
        {
            i=m;

            while(m++)
            {
                if(a[m]==k) i=m;

                else break;
            }


            break;
        }

        else if(a[m]<k)
        {
            b=m+1;



        }

        else e=m-1;


    }

    printf("%d", i);


    return 0;
}
