/** programming example 6.17

avareging a list of numbers

using for loop
**/

#include<stdio.h>

main()
{
    int n,count;

    float x, average, sum=0;
    printf("How many numbers? ");
    scanf("%d", &n);

    for(count=1;count<=n;count++){
        printf("x= ");
        scanf("%f", &x);
        sum+=x;
    }

    average=sum/n;
    printf("%f", average);


    return 0;
}
