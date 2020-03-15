#include<bits/stdc++.h>

using namespace std;

typedef long long int int_64;

int_64 power(int_64 b, int_64 p)
{
    if(p==0)
    {
        return 1;
    }
    else if(p%2==0)
    {
        int_64 temp=power(b, p/2);
        return temp*temp;
    }
    else
    {
        int_64 temp=power(b, p/2);
        return b*temp*temp;
    }

}

int main()
{
    int_64 t, n;

    cin>>t;

    while(t--)
    {
        cin>>n;

        int_64 p=1;

        int_64 b=n-ceil((float)n/2);
        int_64 q=power(10, b);

        cout<<p<<" "<<q<<endl;

    }

    return 0;
}
