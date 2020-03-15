#include<bits/stdc++.h>



using namespace std;

int fu(int *a, int *b)
{
    (*a)++;

    (*b)++;


}

int main()
{

    int a=5, b=300;

    fu(&a, &b);

    printf("%d   %d", a, b);

    return 0;
}
