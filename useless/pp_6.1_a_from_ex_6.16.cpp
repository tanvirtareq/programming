/** programming problem 6.1 a (from exmpl 6.16)

problem:
read in a line of upper case text store in a appropriate array , and then write in lower case

using do for loop ,tolower function
char typ array name letter*/

#include<stdio.h>
#include<ctype.h>


int main()
{
    char letter[80];
    int i, j;


    for(i=0;(letter[i]=getchar())!='\n';i++);



    j=i;


    for(i=0;i<j;i++)

        putchar(tolower(letter[i]));


    return 0;
}

