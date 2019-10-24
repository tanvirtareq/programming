#include<bits/stdc++.h>

using namespace std;

vector<int> prime ;



int countar[1000];

bool a[1000];

void primef()
{

    int count=0;
    for(int i=1;i<=1000;i++)
    {

        if(a[i]==0)
        {
            prime.push_back(i);
            count++;

        }

        countar[i]=count;


    }


}



void seive_prime()
{
    long long int i, j;
    a[0]=1;


    for(i=2;i<=32;i++)
    {
        for(j=i+i;j<=1000;j=j+i)
        {
            a[j]=1;

        }


    }



}

int main()
{
    seive_prime();

    primef();

    int n, c, start, end;

    while(scanf("%d%d", &n, &c)!=EOF)
    {
        int ct=countar[n];

        if(ct%2==0)
        {


           int c1=2*c;

            int mid=ct/2;

            start=mid-c;

            if(start<0) start=0;

            end=mid+c-1;

             if(end>=n) end=ct-1;

//            printf("end=%d  ", end);

//            printf("start=%d  ", start);

            printf("%d %d:", n, c);

            for(int i=start;i<=end;i++)
            {
                printf(" %d", prime[i]);

            }
            puts("");


        }
        else
        {
            int mid=ceil((double)ct/2);

            printf("%d %d:", n, c);

            int start=mid-c/2-1;

            if(start<0) start=0;


            int end=mid+c/2-1;

            if(end>=n) end=ct-1;

            for(int i=start;i<=end;i++)
            {
                printf(" %d", prime[i]);

            }

            puts("");

        }



    }



    return 0;
}
