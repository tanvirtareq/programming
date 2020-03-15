#include<bits/stdc++.h>



using namespace std;

int fu(int *a, int *b)
{
    (*a)++;

    (*b)++;


}

int main()
{
//    int a;

    string ct[6];

    for(int n=0;n<6;n++)
    {
        scanf("%s", ct[n]);
        printf("%s\n", *ct[n]);
    }
    for(int n=0;n<6;n++)
    {
        printf("%s\n", ct[n]);
    }
//    cout<<a;

    return 0;
}
