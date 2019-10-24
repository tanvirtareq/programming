#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long int lld;

int main()
{
    int t, n, k;

    cin>>t;

    while(t--)
    {
        cin>>n>>k;
        int i=0;
        while(n--)
        {
            printf("%c", i%k+'a');
            i++;
        }

        puts("");

    }
	return 0;
}
