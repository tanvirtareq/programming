#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    vector<vector<int> >a;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        vector<int>b;

        for(int j=0; j<=n; j++)
        {
            int temp;

            scanf("%d", &temp);

            b.push_back(temp);
        }

        a.push_back(b);

    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            a[i][j]=a[i][j]/a[i][i];



        }

        for(int j=1;j<n;j++)
        {


        }

    }

    for(int i=0; i<n; i++)
    {


        for(int j=0; j<=n; j++)
        {
            printf("%d ", a[i][j]);

        }

        puts("");

    }

    return 0;
}
