#include<bits/stdc++.h>

using namespace std;

int isconso(char c)
{
    if(c=='a'||
    c=='e'||
    c=='i'||
    c=='o'||
    c=='u') return 0;

    else return 1;

}

int main()
{
    char c, p, check='v';
    int flag=1;

    while(cin>>c)
    {
        if(isconso(c)&&check=='c')
        {
            flag=0;
            check='c';
        }
        else if(isconso(c)&&c!='n') check='c';
        else check='v';
    }
    if(flag==1&&check=='v')
        cout<<"YES"<<endl;

    else cout<<"NO"<<endl;

    return 0;
}

