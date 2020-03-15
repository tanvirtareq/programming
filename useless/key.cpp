#include<stdio.h>
#include<string.h>

int main()
{
	int i, j,k, c=0, t;

	char a[101];

	scanf("%d%*c", &t);

	for(k=1;k<=t;k++)
	{
		gets(a);

		j=strlen(a);

		for(i=0;i<j;i++)
		{
			if(a[i]=='a'||a[i]=='d'||a[i]=='g'||a[i]=='j'||a[i]=='m'||a[i]=='p'||a[i]=='t'||a[i]=='w'||a[i]==32)
			c=c+1;


			if(a[i]=='b'||a[i]=='e'||a[i]=='h'||a[i]=='k'||a[i]=='n'||a[i]=='q'||a[i]=='u'||a[i]=='x')
			c=c+2;

			if(a[i]=='c'||a[i]=='f'||a[i]=='i'||a[i]=='l'||a[i]=='o'||a[i]=='r'||a[i]=='v'||a[i]=='y')
			c=c+3;

			if(a[i]=='z'||a[i]=='s')
			c=c+4;

		}

		printf("Case #%d: %d\n",k, c);
		c=0;

	}


	return 0;
}
