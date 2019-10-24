#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, count=0;

    bool fl=0;

    vector<char> s;

    scanf("%d%*c", &n);

    for(int i=1;i<=n;i++)
    {
        char ch;

        scanf("%c", &ch);

        if(ch=='0')
        {
             s.push_back(ch);
             count++;
        }

        else if(ch=='1'&&fl==0)
        {
            fl=1;
        }
    }

    if(fl!=0)
    {
        printf("1");
        for(int i=1;i<=count;i++)
        {
            printf("0");
        }
    }

    else {

        printf("0");
    }



    return 0;
}
