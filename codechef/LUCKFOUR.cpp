#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, cnt;
    char ch;
    scanf("%d%*c", &t);

    while(t--)
    {
        cnt=0;
        while(1)
        {
            scanf("%c", &ch);
//            printf("%d", ch);
            if(ch==10) break;
            if(ch=='4') cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
