#include<bits/stdc++.h>

using namespace std;

int main()
{
    int y, r, t;

    cin>>t;
    while(t--)
    {
        cin>>y;
//        y=y-1;
//        float yf=(float)y*365.25;
//        y=(int)yf;
//        y=y+1;
//        r=y%7;
    r=((int)((y-1)*365.2475+1))%7;
    cout<<r<<endl;

    switch(r)
    {
    case 1:
        cout<<"Friday"<<endl;
        break;

    case 2:
        cout<<"Saturday"<<endl;
        break;

    case 3:
        cout<<"Sunday"<<endl;
        break;

    case 4:
        cout<<"Monday"<<endl;
        break;

    case 5:
        cout<<"Tuesday"<<endl;
        break;

    case 6:
        cout<<"Wednesday"<<endl;
        break;

    case 0:
        cout<<"Thursday"<<endl;
        break;
    }

    }

    return 0;
}

