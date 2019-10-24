#include<stdio.h>
#include<string.h>

int new_roll(int n, double marks[])
{
    int i, j, student;
    double max;
    for(i=1;i<=n;i++)
    {
        max=marks[0];
        for(j=1;j<=n;j++)
        {
            if(max<marks[j])
            {
                max=marks[j];
                student=j;
            }

        }
        printf("%d|______previus roll=%d____marks=%lf\n",i , student  ,  max);
        marks[student]=0;
    }
}





main()
{
    int n, i1, i2, i, max;
    double a[200][3], marks[200];
    char student[200];

    scanf("%d", &n);

    for(i1=1;i1<=n;i1++)
    {
        printf("student name :");

        scanf("%s", &student[i1]);

        for(i2=1;i2<=3;i2++)
        {
            printf("%d students %d term xm marks=", i1, i2);
            scanf("%lf", &a[i1][i2]);
        }

        marks[i1]=a[i1][1]*25/100+a[i1][2]*25/100+a[i1][3]*50/100;

        printf("average marks of %d student =%.2f\n", i1, marks[i1]);
    }
    printf("\n\n");

    new_roll(n , marks);

}
