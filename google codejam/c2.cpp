#include<bits/stdc++.h>

using namespace std;

/// for seive prime

#define sz 100000

bool chk[sz];
vector<long long int> prime;

void seive()
{
    prime.push_back(2);

    for(int i=3;i*i<=sz;i+=2)
    {
        if(chk[i]==0) {

        for(long long int j=i+i;j<=sz;j+=i)
            chk[j]=1;

        }
    }


    for(long long int i=3;i<=sz;i+=2)
    {
        if(chk[i]==0){
            prime.push_back(i);
        }
    }


}



int main()
{
    seive();

    cout<<prime[0]<<endl;

	return 0;
}

