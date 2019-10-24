#include<bits/stdc++.h>
#include<stdio.h>
int main()
{
	long long unsigned n, a, b, seat;

	int count, i, j, k, temp;

	count=0;

	char c;

	scanf("%llu%llu%llu%*c", &n, &a, &b);

	seat=0;

	while(n--)
	{
		scanf("%c", &c);

		if(c=='*'&&seat!=0)
        {
            if(a>b)
            {
                temp=ceil((float)seat/2);

//                printf("temp=%d\n", temp);

                if(temp>a)
                {
                    count=count+a;

//                    printf("count=%d\t%d\n", count, n);

                    a=a-a;
                }

                if(temp<=a)
                {
                    count=count+temp;

//                    printf("count=%d\t%d\n", count, n);

                    a=a-temp;
                }
                temp=seat/2;

                if(temp>b)
                {
                    count=count+b;

//                    printf("count=%d\t%d\n", count, n);

                    b=b-b;
                }
                if(temp<=b)
                {
                    count=count+temp;
//                    printf("count=%d\t%d\n", count, n);

                    b=b-temp;
                }
            }
            else
            {
                temp=ceil((float)seat/2);

                if(temp>b)
                {
                    count=count+b;

//                    printf("count=%d\t%d\n", count, n);

                    b=b-b;
                }
                if(temp<=b)
                {
                    count=count+temp;

//                    printf("count=%d\t%d\n", count, n);

                    b=b-temp;
                }
                temp=seat/2;

                if(temp>a)
                {
                    count=count+a;

//                    printf("count=%d\t%d\n", count, n);

                    a=a-a;
                }

                if(temp<=a)
                {
                    count=count+temp;

//                    printf("count=%d\t%d\n", count, n);
                    a=a-temp;
                }
            }

            seat=0;
        }
         else if(c=='.') seat++;
	}


	            if(a>b)
            {
                temp=ceil((float)seat/2);

                if(temp>a)
                {
                    count=count+a;

//                    printf("count=%d\t%d\n", count, n);

                    a=a-a;
                }

                if(temp<=a)
                {
                    count=count+temp;

//                    printf("count=%d\t%d\n", count, n);
                    a=a-temp;
                }
                temp=seat/2;

                if(temp>b)
                {
                    count=count+b;

//                    printf("count=%d\t%d\n", count, n);

                    b=b-b;
                }
                if(temp<=b)
                {
                    count=count+temp;
//                    printf("count=%d\t%d\n", count, n);

                    b=b-temp;
                }
            }
            else
            {
                temp=ceil((float)seat/2);

                if(temp>b)
                {
                    count=count+b;

//                    printf("count=%d\t%d\n", count, n);

                    b=b-b;
                }
                if(temp<=b)
                {
                    count=count+temp;

//                    printf("count=%d\t%d\n", count, n);
                    b=b-temp;
                }
                temp=seat/2;

                if(temp>a)
                {
                    count=count+a;

//                    printf("count=%d\t%d\n", count, n);

                    a=a-a;
                }

                if(temp<=a)
                {
                    count=count+temp;

//                    printf("count=%d\t%d\n", count, n);
                    a=a-temp;
                }
            }

	printf("%d", count);

	return 0;
}
