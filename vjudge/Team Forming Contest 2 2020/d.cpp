#include <bits/stdc++.h>
using namespace std;
int n,k,i,j;
string s;
bool a[28];
int main()
{
    cin>>k;
    cin>>s;
    int n=s.size();
    int i=0, j=s.size()-1;
    vector<int> v(k, 0);
    int c=0;
    while(i<=j)
    {
        if(s[i]!='?' and s[j]!='?' and s[i]!=s[j])
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }

        else if(s[i]=='?' and s[j]!='?')
        {
            s[i]=s[j];
        }


        else if(s[j]=='?' and s[i]!='?')
        {
            s[j]=s[i];
        }
        v[s[i]-'a']=1;
        v[s[j]-'a']=1;

        i++;
        j--;
    }

    for (int j=k-1; j>=0 && a[j]; j--);

    for (int i=(n-1)/2; i>=0; i--)
        if (s[i]=='?')
        {
            if (j<0) j=0;
            s[i]=s[n-1-i]=j+'a';
            a[j]=true;
            while (j>=0 && a[j])
                j--;
        }
    if (j<0)
        cout<<s;
    else
        cout<<"IMPOSSIBLE";
}
