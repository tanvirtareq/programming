#include<stdio.h>
#include<stdlib.h>

void check()
{
     char str1[10], str2[10];
    while(1)
    {
        scanf("%s %s", str1, str2);
        printf("%d\n", strcmp(str1, str2));
    }
    return;
}
void take(char a[5][10])
{
    int i;

    for(i=0;i<5;i++)
    {
        scanf("%s", a[i]);
    }
    puts("\n");

    return;
}

void print(char a[5][10])
{
    int i;

    for(i=0;i<5;i++)
    {
        printf("%s  ", a[i]);
    }
    puts("\n");

    return;
}

void sort(char a[5][10])
{
    int i=5, j;
    char temp[10];
    while(i--)
    {
        for(j=0;j<4;j++)
        {
            if(strcmp(a[j], a[j+1])==1)
            {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j+1]);
                strcpy(a[j+1], temp);

            }
        }

    }

    return;
}

int main()
{
   char a[5][10];
   take(a);
   print(a);
   sort(a);
   print(a);


}
