#include<bits/stdc++.h>

using namespace std;

int main()
{
    char a='\0', b='\0', c='\0', ch;
    bool ab=0, ba=0;

    while(cin>>a)
    {
        if(a=='\n'||a=='\0') break;
        if(a=='A'&&b=='B'&&c!='A') ba=1;
        else if(a=='B'&&b=='A'&&c!='B') ab=1;

        c=b;
        b=a;
    }
    if(ab==1&&ba==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
