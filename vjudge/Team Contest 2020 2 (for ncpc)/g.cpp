#include<bits/stdc++.h>
using namespace std;

double n,k;
double pro[1005];
double tareq[1005];

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>pro[i];
        pro[(int)n+i]=pro[i];
    }

    tareq[0]=(k/n);

    for(int i=1;i<n;i++){
        tareq[i]=tareq[i-1]*((n-k-(double)i+1.0)/(n-(double)i));
    }

    for(int i=n;i<n+n;i++){
        double sum=0,ans=0;
        for(int j=i,k=0;j>=0;j--,k++){
            ans+=tareq[k]*pro[j];

        }
        cout<<setprecision(15)<<fixed<<ans;
        if(i!=n+n){
            cout<<' ';
        }
    }
    cout<<endl;



}
