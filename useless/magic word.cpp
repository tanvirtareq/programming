#include<stdio.h>
#include<math.h>
#include<string.h>

char b[100];

int mgcchk(int l, int m, char b[])
{
    int i, j;
    for(i=1,j=l;i<=l/2+1;i++,j--)
    {
        if(b[i]!=b[j])
        {

            return 0;
        }
    }

    for(i=1,j=l;i<=l;i=i+m,j=j-m)
    {
        if(b[i]!=b[j])
        {
            return 0;
        }
    }

    return 1;

}



int sqrchk(int l)
{
    int  d;

    double d1;

    d=sqrt(l);


      d1=sqrt(l);

    if(d==d1) return d;

    else return 0;
}

int main()
{
    char a[100], c;

    int t,k,  i, l,j, wl, m;

    scanf("%d%*c", &t);

    for(i=1;i<=t;i++)
    {
        j=1;

        gets(a);

        l=strlen(a);

        printf("%d\n",l);

        for(k=0;k<l;)
        {
            if((a[k]<='z')&&(a[k]>='a'))
            {
                b[j]=a[k];

            j++;
            }

            k++;

        }



     wl=j-1;

     m=sqrchk(wl);
        if(m==0) printf("Case #%d:\n No magic :( \n", i);
        else
        {
           if(mgcchk(wl,m, b))
            {
                printf("Case #%d:\n%d\n", i, m);
            }

           else printf("Case #%d:\n No magic  :(\n", i);
        }
    }

    return 0;
}

// sator arepo tenet opera rotas
