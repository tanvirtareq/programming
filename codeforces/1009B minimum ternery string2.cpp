#include<bits/stdc++.h>

using namespace std;

void fnd(vector<char>v)
{
    int i,j;

    for(i=0;i<v.size();i++)
    {
        for(j=0;j<v.size()-1;j++)
        {
            if(v[j]=='2'&&v[j+1]=='0'||v[j]=='0'&&v[j+1]=='2')
            {
                continue;
            }
            else
            {
                if(v[j]>v[j+1])
                {
                    char temp=v[j];
                    v[j]=v[j+1];
                    v[j+1]=temp;
                }
            }

        }

    }
        for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
    cout<<endl;

    return;

}

int main()
{
    vector<char> v, srt;

    char ch, p1,p2;
    while(cin>>ch)
    {
        v.push_back(ch);

    }

    fnd(v);


    return 0;
}

