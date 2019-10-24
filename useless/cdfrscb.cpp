#include<stdio.h>
int main()
{
	long long unsigned n, a, b, seat;

	int count, i, j, k, temp;

	count=0;

	char c;

	scanf("%llu%llu%llu%*c", &n, &a, &b);

	while(n--)
	{
		seat=0;

		scanf("%c", &c);

		if(c=='*')
		{

            if(a<temp)
			{
				count=a;

				a=a-a;


			}
			else
			{
				count=temp;
				a=a-temp;


			}


		seat=0;

		}

		else
		{
			seat++;


		}

		if(a<temp)
			{
				count=a;

				a=a-a;


			}
			else
			{
				count=temp;
				a=a-temp;


			}



	}

	printf("%d", count);

	return 0;
}
