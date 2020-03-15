/** 6.1 b (from ex 6.16)
read in a line of mixed text store in a appropriate array , and then write in lower case and upper case letters reversed,
all digits replaced by 0, all other charrecters replaced by asterisks(*)

char type array name letter
programming will reading input char untill an end of line char has been read

using library function, for loop
*/

#include<stdio.h>
#include<ctype.h>


int main()
{
    char letter[80];
    int i, j;

    for(i=0;(letter[i]=getchar())!='\n';i++);

    j=i;
    for(i=0;i<j;i++)
    {
        if(letter[i]>='A'&&letter[i]<='Z')
            putchar(tolower(letter[i]));

        else if(letter[i]>='a'&&letter[i]<='z')
            putchar(toupper(letter[i]));

        else if(letter[i]>='0'&&letter[i]<='9')
            putchar('0');

        else
            putchar('*');

    }

    return 0;
}
