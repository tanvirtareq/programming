 #include <stdio.h>

 #include<math.h>


 int main()
{
     char x1[100];

     int x2[100], i, d=0;

     scanf("%s", x1);


     for(i=0;x1[i]!='\0';i++)
     {
         if(x1[i]=='1')
         {
             x2[i]=1;
         }

         else if(x1[i]=='0')
         {
             x2[i]=0;
         }


     }

     for(i=i-1;i>=0;i--)
     {
         d=d+x2[i]*pow(2, i);
     }
     printf("%d", d);
}
