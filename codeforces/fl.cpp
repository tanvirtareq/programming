#include<bits/stdc++.h>
using namespace std;
int main() {
    int N,T,A,H,R, loc=1, x=0, min=INT_MAX;
    cin >> N;
    cin >> T >> A;
    while(N--) {
    	x++;
        cin >> H;
        R = T-(H*0.006);
        int ans = abs(R-A);
        if(ans<min)
        {
        	min=ans;
        	loc=x;
        }



    }
    cout<<loc<<endl;
    return 0;
    
}