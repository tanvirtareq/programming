/** programming example6.10

avareging a list of numbers

using while
**/

#include<stdio.h>

main()
{
    int n,count=1;

    float x, average, sum=0;
    printf("How many numbers? ");
    scanf("%d", &n);

    while(count<=n){
        printf("x= ");
        scanf("%f", &x);
        sum+=x;
        ++count;
    }

    average=sum/n;
    printf("%f", average);


    return 0;
}
