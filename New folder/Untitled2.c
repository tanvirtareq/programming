#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, rt, flag;

    for(i=2;i<=100;i++)
    {
        flag=1;
        rt=sqrt(i)+1;
        for(j=2;j<rt;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1) printf("%d\n", i);
    }


}
