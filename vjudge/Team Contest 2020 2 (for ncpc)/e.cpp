#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-9

int main()
{
    int ti[6],tar;
    double x;
    for(int i=0;i<4;i++){
        cin>>x;
        ti[i]=(x+EPS)*100.0;
    }
    cin>>x;
    tar=(x+EPS)*100.0;
    sort(ti,ti+4);

    int sum=0;

    for(int i=1;i<4;i++){
        sum+=ti[i];
    }

    if(sum<=tar*3){
        cout<<"infinite\n";
        return 0;
    }
    sum=0;
    for(int i=1;i<4;i++){
        sum+=ti[i];
    }

    if((3*tar-ti[1]-ti[2])<ti[0]){
        cout<<"impossible\n";
        return 0;
    }

    cout<<setprecision(2)<<fixed<<double(3*tar-ti[1]-ti[2]+EPS)/100.<<endl;
}
