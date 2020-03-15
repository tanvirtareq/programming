#include<bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> a;

    int x, c, count=0;

    while(scanf("%d", &x)!=EOF)
    {
        a.push_back(x);


    }

    sort(a.begin(), a.end());

    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;

    }

    for(int i=0;i<a.size();i++)
    {
        if(count==0)
        {
            c=a[i];
            count++;

        }
        else if(a[i]==c)
            count++;

        else if(a[i]!=c)
        {
            printf("%d %d\n", c, count);

            count=0;

        }


    }

    return 0;
}
