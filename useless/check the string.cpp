#include<bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("chck.txt", "w", stdout);

//    freopen("chkinput.txt", "r", stdin);

    int a=0,b=0, d=0, x, y;

    char c;

    while(scanf("%c", &c)==1)
    {
        if(c=='\n') break;

        if(c=='a') a++;

        else if(c=='b'&&a>0) b++;

        else if(c=='c'&&b>0) d++;

//        printf("a=%d  b=%d  c=%d\n", a, b, d);

    }

//    printf("a=%d  b=%d  c=%d\n", a, b, d);

    if(d>0&&(d==a||d==b)) cout<<"YES"<<endl;

    else cout<<"NO"<<endl;


    return 0;
}
