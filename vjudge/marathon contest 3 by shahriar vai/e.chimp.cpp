#include<bits/stdc++.h>

using namespace std;

long long int lwrb, uprb, target;

bool binary_searchf(vector<long long int>v,long long int key)
{
    lwrb=0;
    uprb=v.size()-1;
    long long int mid;
    while(lwrb<=uprb)
    {
        mid=(lwrb+uprb)/2;
        if(v[mid]==key)
        {
            target=mid;
            return true;
        }
        else if(v[mid]>key)
        {
            uprb=mid-1;
        }
        else lwrb=mid+1;
    }

    swap(lwrb, uprb);

    return false;

}

int main()
{
    vector<long long int>v;

    long long int n, q;

    cin>>n;
    while(n--)
    {
        long long int x;
        cin>>x;
        v.push_back(x);

    }
    cin>>q;
    while(q--)
    {
        long long int k, s, t;
        cin>>k;
        if(binary_searchf(v, k))
        {
            long long int x=target;
            while(1)
            {
                target--;
                if(target<0) break;
                else
                if(v[target]!=k) break;
            }
            s=target;

            target=x;
            while(1)
            {
                target++;
                if(target==v.size()) break;
                else
                if(v[target]!=k) break;
            }
            t=target;
        }
        else
        {
            s=lwrb;
            t=uprb;
        }
        if(s>=0&&t<v.size()) cout<<v[s]<<" "<<v[t]<<endl;
        else if(s<0&&t<v.size()) cout<<"X "<<v[t]<<endl;
        else if(s>=0&&t>=v.size()) cout<<v[s]<<" X"<<endl;
        else cout<<"X X"<<endl;

    }

    return 0;
}
