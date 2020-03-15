#include<bits/stdc++.h>

using namespace std;

typedef long long li;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    li a, b;

    cin>>a>>b;

    if(b>a) swap(a, b);

    if(a%b==0)
    {
        cout<<0<<endl;
        return 0;
    }

    li dif=a-b;

    if(b%dif==0)
    {
        cout<<0<<endl;
        return 0;
    }

    vector<li> v;

    for(li i=1;i*i<=dif;i++)
    {
        if(dif%i==0)
        {
            v.push_back(i);

            if(i*i!=dif)
            {
                v.push_back(dif/i);
            }

        }

    }

    sort(v.begin(), v.end());

    li ans;
    li anss;

    li q=v[0];

    li k=q-b%q;

    li x=((b+k)/q)*(a+k);
    anss=k;
    ans=x;

    for(li i=1;i<v.size();i++)
    {

        li q=v[i];

        li k=q-b%q;

//        cout<<k<<endl;

        li x=((b+k)/q)*(a+k);
//        cout<<"asgh"<<x<<endl;
        if(x>=0 and  ans>x)
        {
            ans=x;
            anss=k;

        }
        else if(x>=0 and ans==x)
        {
            if(anss>k)
                anss=k;

        }

    }
    cout<<anss<<endl;

}

/*

948248258 533435433

*/
