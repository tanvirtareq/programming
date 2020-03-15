/** programming problem 6.4

avareging a list of numbers

number of list is not predefined  read number untill x=0

using while
**/

#include<stdio.h>

main()
{
    int count=1;

    float x, average, sum=0;

    while((scanf("%f", &x))){
        if(x==0) break;

        sum+=x;
        ++count;
    }

    count=count-1;
    average=sum/count;
    printf("%f", average);


    return 0;
}
