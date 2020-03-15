#include<bits/stdc++.h>

int main()
{
    int i, j, max, tm, s, b;
    int ai=0;
    while(scanf("%d%d", &i, &j)!=EOF)
    {
        if (i>j)
        {
            b=i;
            s=j;
        }

        else{
            b=j;
            s=i;
        }

        max=0;
        for(int k=s; k<=b; k++)
        {

            int temp=k;
            ai=0;

            for(; temp!=1;)
            {
                ai++;

                if(temp%2==0)
                    temp=temp/2;

                else temp=3*temp+1;

            }
            ai++;
            if(ai>max) max=ai;


        }
        printf("%d %d %d\n",i, j, max);

    }
    return 0;
}
