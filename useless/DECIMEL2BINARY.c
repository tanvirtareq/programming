 #include <stdio.h>
 int main()
{
     int x, n[100];
     int d, i;
     scanf("%d" , &x);

     for(i=0;x!=0;i++)
     {
         n[i]=x%2;
         x=x/2;
     }

     i=i-1;

     while(i>=0)
     {
         printf("%d", n[i]);
         i=i-1;
     }
}
