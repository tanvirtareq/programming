/// 6.1 a (from ex 6.9)
///read in a line of upper case text store in a appropriate array , and then write in lower case

#include<stdio.h>
#include<ctype.h>


int main()
{
    char letter[80];
    int i=0, j;

    while((letter[i]=getchar())!='\n')
        i++;

    j=i;
    i=0;
    while(i<j){
        putchar(tolower(letter[i]));
        i++;
    }

    return 0;
}
