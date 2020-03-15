#include<bits/stdc++.h>

using namespace std;

int naive_multiplicative_inverse(int x, int m)
{
    int i=1;
    while(i<=x)
    {
        if((x*i)%m==0)
        {
            return i;
        }
        i++;
    }
    return -1;

}

int modular_multiplicative_inverse(int x, int m)
{
    for(int i=1;;i++)
    {
        if((floor(m*i+1)/(float)x)==(m*i+1)/x) return (m*i+1)/x;
    }
}

int main()
{

    int m=2;

    for(int i=1;i<=10;i++)
    {
        int x=naive_multiplicative_inverse(i, m);
        int y=modular_multiplicative_inverse(i, m);
        cout<<i<<"  "<<x<<"    "<<y;
        if(x==y) cout<<"   yes"<<endl;

        else cout<<"  no"<<endl;

    }

    return 0;
}
