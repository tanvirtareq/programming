#include<bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    vector<int> v;
    cin>>k;
    int an=0;
    int x;
    while(cin>>x)
    {
        v.push_back(x);
    }
//    cout<<v[0]<<endl;

    sort(v.begin(), v.end(), greater<int>());

    int c=0;
//    cout<<v[0]<<endl;
    for(int i=0;i<v.size();i++)
    {
//        cout<<v[i]<<endl;
        if(an>=k)
            break;

        an+=v[i];
//        cout<<k<<endl;
        c++;
    }
    if(an>=k)
    cout<<c<<endl;

    else cout<<-1<<endl;

    return 0;
}
