#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin>>n;

    int j=0;

    priority_queue<int, vector<int> ,greater<int> > pq;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;

        if(pq.empty())
        {
            j++;
        }

        if(!pq.empty())
        {
            while(!pq.empty() and  pq.top()<=i)
                pq.pop();
        }

        if(x>i) pq.push(x);

    }

    cout<<j<<endl;

	return 0;
}

