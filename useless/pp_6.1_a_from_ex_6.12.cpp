/** programming problem 6.1 a (from exmpl 6.12)

problem:
read in a line of upper case text store in a appropriate array , and then write in lower case

using do while loop ,tolower function
char typ array name letter*/

#include<stdio.h>
#include<ctype.h>


int main()
{
    char letter[80];
    int i=-1, j;


    do   i++;
    while((letter[i]=getchar())!='\n');


    j=i;
    i=0;

    do{
        putchar(tolower(letter[i]));
        i++;
    }while(i<j);

    return 0;
}

