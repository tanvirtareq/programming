#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> v;



    for(int i=1;i*i<=n and i<10;)
    {
        if(n%i==0)
        {
            v.push_back(i);
            n=n/i;
            if(n<10)
            {
               v.push_back(n);
               break;
            }
            if(i==1) i++;
        }

    }

 	return 0;
}




