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
        printf("%d|______student id=%d____marks=%lf\n",i , student  ,  max);
        marks[student]=0;
    }
}





main()
{
    int n, i1, i2, i, max;
    double a[2000], marks[2000];
    int student[2000];

    scanf("%d", &n);

    for(i1=1;i1<=n;i1++)
    {
        printf("student id :");

        scanf("%d", &student[i1]);

        printf("marks=");

        scanf("%lf", &marks[i1]);
        printf("\n");
    }
    printf("\n\n");

    new_roll(n , marks);

}
