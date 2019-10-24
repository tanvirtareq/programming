#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, n , q;
    scanf("%d", &t);

    for(int i=1;i<=t;i++)
    {
        printf("Case %d:\n", i);
        string s;
        scanf("%*c%*c%s", s.c_str());
        scanf("%d", &q);
        while(q--)
        {
            char ch;
            scanf("%*c%*c%c", &ch);
            if(ch=='I')
            {
                int x, y;
                scanf("%d%d", &x, &y);
                int tm=s.size();
                for(int i=x;i<=min(y,tm);i++)
                {
                    if(s[i-1]=='0') s[i-1]='1';
                    else s[i-1]='0';
                }
            }
            else
            {
                int x;
                scanf("%d", &x);
                if(x<=s.size());
                printf("%c\n", s[x-1]);


            }

        }

    }

    return 0;
}
