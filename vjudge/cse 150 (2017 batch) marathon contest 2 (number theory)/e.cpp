#include<bits/stdc++.h>
#define sz 5000
typedef long long unsigned llu;

using namespace std;
string f[sz+1];

string pls(string x, string y)
{
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    string z;
    int c=0;
    for(int i=0;i<max(x.size(),y.size());i++)
    {
        if(i>=y.size())
        {
            z.push_back(x[i]+c%10);
            c=c/10;
        }
        else if(i>=x.size())
        {
            z.push_back(y[i]+c%10);
            c=c/10;
        }
        else {
        int ad=x[i]-'0'+y[i]-'0'+c;
        c=ad/10;
        z.push_back(ad%10+'0');
        }
    }
    if(c!=0) z.push_back(c+'0');
    reverse(z.begin(), z.end());
    return z;

}

void fi()
{
    f[0]="0";
    f[1]="1";
    for(llu i=2;i<=sz;i++)
    {
        f[i]=pls(f[i-1],f[i-2]);
//        cout<<f[i]<<endl;

    }
    return;

}


int main()
{

   fi();
   llu n;
   while(cin>>n)
   {
       cout<<"The Fibonacci number for "<<n<<" is "<<f[n]<<endl;
   }

    return 0;
}



