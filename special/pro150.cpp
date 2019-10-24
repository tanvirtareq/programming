#include<bits/stdc++.h>
using namespace std;

int main()
{
   unsigned  long n;
   cin>>n;
   vector<unsigned long> v;
   unsigned long p;
   v.push_back(9);

   for(int i=1;i<10;i++)
   {
       long long x=v[i-1]+9*(i+1)*pow(10,i);
       v.push_back(x);
   }
   if(n<10)
    cout<<n<<endl;
   else if(n<100)
   {
       p=v[0]+2*(n-9);
       cout<<p<<endl;
   }
   else if(n<1000)
   {
       p=v[1]+3*(n-99);
       cout<<p<<endl;
   }
   else if(n<10000)
   {
       p=v[2]+4*(n-999);
       cout<<p<<endl;
   }
   else if(n<100000)
   {
       p=v[3]+5*(n-9999);
       cout<<p<<endl;
   }
   else if(n<1000000)
   {
       p=v[4]+6*(n-99999);
       cout<<p<<endl;
   }
   else if(n<10000000)
   {
       p=v[5]+7*(n-999999);
       cout<<p<<endl;
   }
   else if(n<100000000)
   {
       p=v[6]+8*(n-9999999);
       cout<<p<<endl;
   }
   else if(n<1000000000)
   {
       p=v[7]+9*(n-99999999);
       cout<<p<<endl;
   }
   else if(n<1000000000)
   {
       p=v[7]+9*(n-99999999);
       cout<<p<<endl;
   }
   else if(n<10000000000)
   {
       p=v[8]+10*(n-999999999);
       cout<<p<<endl;
   }
}
