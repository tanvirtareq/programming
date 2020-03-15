#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, ni,t, check, temp,  j, k;
    scanf("%d", &t);
    string str;
       getline(cin,str);
    char ch;
    while(t--)
    {
       long long maxnumb=0;
       long long a[110];
       getline(cin,str);
       n=0;
       for(int i=0;i<str.size();){
            long long p=0;
            while(str[i]!=' ' && i<str.size()){
                p=p*10+(str[i]-'0');

                i++;
            }
            i++;
            a[n++]=p;

       }

    for(int j=0;j<n-1;j++){

            for(k=j+1;k<n;k++){
                maxnumb=max(maxnumb,__gcd(a[j],a[k]));
            }
        }

        printf("%lld\n", maxnumb);

    }



    return 0;
}
