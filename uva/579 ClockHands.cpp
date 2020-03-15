/**
12 hour = 360 degree
1 hour=30 degree

60 minute=360 degree
1 minute=6 degree
special case 0 minute=360 degree

for 60 minute hour hand goes 30 degree
for 1 minute hourhand goes 0.5 degree




*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int h, m;
    while(scanf("%d:%d", &h, &m))
    {
        if(h==0&&m==0) break;

        double ans=abs((h*30)%360+m*0.5-m*6);
        if(ans>180) ans=360-ans;

        printf("%.3lf\n", ans);
    }

}

