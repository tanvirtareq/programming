#include<bits/stdtr1c++.h>

using namespace std;

int main()
{
    double x;

    int y;

    for(double i=-1;i<=1;i=i+0.01)
    {
        y=ceil(3*i-2);

        printf("x=%lf\ty=%d\n", i, y);

    }

    return 0;
}
