#include<stdio.h>

void sort(int *a,int *b)
{
    int temp;
    if(a>b)
    {
        temp=*a;
        *a=*b;
        *b=temp;

    }
    return;
}
void print_ar(int ar[])
{
    int i=0;
    for(i=0;i<7;i++)
    {
        printf("%d", ar[i]);
    }
    puts("");
    return;
}

void buble_sort(int ar[])
{
    int i,j, temp;
    for(j=0;j<7;j++)
    {
        for(i=0;i<6;i++)
        {
            if(ar[i]>ar[i+1])
            {
                temp=ar[i];
                ar[i]=ar[i+1];
                ar[i+1]=temp;

            }
            print_ar(ar);

        }
        puts("\n");
    }



    return ;
}

int main()
{
    int ar[7]={3, 6,1,4,2,9,7};
    buble_sort(ar);

    return 0;
}
