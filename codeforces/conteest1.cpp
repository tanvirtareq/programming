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

 
 
int main()
{
 int t;
 cin>>t;
 while(t--){
  int n;
  cin>>n;
  vector<int>a,b;
  for(int i=0;i<n;i++)
    cin>>a[i];
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++)
    cin>>b[i];
  sort(b.begin(),b.end());
  for(int i=0;i<n;i++)
    cout<<a[i]<<" \n"[i==n];
  for(int i=0;i<n;i++)
    cout<<b[i]<<" \n"[i==n];

 } 
 return 0;
}