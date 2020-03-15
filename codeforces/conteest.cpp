/**Bismillahhirrahmannirrahim*/
/** coding is fun if u enjoy it*/
 
/**###########MAHIN##################
###########u##have##to###############
#########work#####hard###############
#####for#######ur#######brother######
########################*/
 
 
#include<bits/stdc++.h>
 
 
using namespace std;
 
#define SZ 112345
#define ll long long
vector<ll>prime;
bool mr[SZ];
void gen_prime()
{
  for(int i=2;i<SZ;i++)
    mr[i]=true;
  prime.push_back(2);
  for(int i=3;i*i<=SZ;i+=2){
    if(mr[i]){
      for(int j=i*i;j<=SZ;j+=i)
        mr[j]=false;
    }
  }
  for(int j=3;j<=SZ;j+=2){
    if(mr[j])
      prime.push_back(j);
  }
}
 
ll segSieve(ll a,ll b)
{
  ll cnt=0;
  bool isprime[b-a+1];
  for(ll i=0;i<=b-a+1;i++)
    isprime[i]=true;
  if(a==1)
    isprime[0]=false;
  for(ll i=0;prime[i]*prime[i]<=b;i++){
    ll cur=prime[i];
    ll base=cur*cur;
    if(base<a)
      base=((a+cur-1)/cur)*cur;
 
    for(ll j=base;j<=b;j+=cur)
      isprime[j-a]=false;
  }  
  for(ll i=0;i<=b-a;i++){
    if(isprime[i])
      cnt++;
  }
  return cnt;
}
 
 
int main()
{
  gen_prime();
  int t;
  cin>>t;
  for(int k=1;k<=t;k++){
    ll a,b;
    cin>>a>>b;
    cout<<"Case "<<k<<": "<<segSieve(a,b)<<endl;
 
  }
 return 0;
}