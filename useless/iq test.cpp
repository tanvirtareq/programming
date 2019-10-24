
#include<bits/stdc++.h>

using namespace std;

int ismanaged(string s)
{
    bool hp=0, ep=0, l1p=0, l2p=0, op=0;

    for(int i=0;i<s.size();i++)
    {
        if(hp!=1&&s[i]=='h')
        hp=1;

        else if(hp==1&&ep!=1&&s[i]=='e') ep=1;
        else if(ep==1&&l1p!=1&&s[i]=='l') l1p=1;
        else if(l1p==1&&l2p!=1&&s[i]=='l') l2p=1;
        else if(l2p==1&&op!=1&&s[i]=='o')
        {
            op=1;
            return 1;
        }
    }

    return 0;

}

int main()
{

     string s;

     cin>>s;

     if(ismanaged(s)) cout<<"YES"<<endl;

     else cout<<"NO"<<endl;

    return 0;
}


