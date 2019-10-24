#include<stdio.h>

int c[26];
int main()
{
	int t, i, j;
	char n;

	scanf("%d%*c", &t);


	while(t--)
	{
		while(1==scanf("%c", &n))
		{
			if(n==32||n=='\n') break;
			else
            c[n-'a']=1;

		}
		j=0;

		for(i=0;i<26;i++)
		j=j+c[i];

		printf("%d\n", j);





	}


	return 0;
}
