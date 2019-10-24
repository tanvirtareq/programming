#include<bits/stdc++.h>

using namespace std;

int main()
{
    int pos=0, n, i=0, ni=0;

    string s, ans;

    vector<string>v;
    while(cin>>s)
    {
        i++;
        v.push_back(s);

        if(i==0)
        {
            ans=v[i];
            if(v[i]=="pair"){
               ni=2;
             ans+="<";
             pos=1;
            }

        }
        else
        {
            if(v[i]=="pair")
            {

                if(v[i-1]=="int")
                {
                    cout<<","<<v[i]<<"<";
                    ni+=2;
                }
                else
                {
                    cout<<v[i]<<",";
                    ni++;
                }

            }
            else
            {


            }

        }
    }

    return 0;
}
