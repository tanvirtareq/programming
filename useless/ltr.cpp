#include<stdio.h>
int c[26];
int main()
{
    int i,t, j;

    char n;

    scanf("%d%*c", &t);

    for(i=0;i<t;i++)
    {
        while(1==scanf("%c", &n))
        {
            if(n==32||n=='\n') break;

          //  else
            //{
              //  c[n-'a']++;
            //}
        }
    }


    return 0;
}
