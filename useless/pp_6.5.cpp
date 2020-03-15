/** programming problem  6.5

avareging a list of numbers

number of list is not predefined  read number untill x=0

using for loop
**/

#include<stdio.h>

main()
{
    int count;

    float x, average, sum=0;

    for(count=1;(scanf("%f", &x)), x!=0;count++)
        sum+=x;

        count=count-1;
    average=sum/count;
    printf("%f", average);


    return 0;
}
