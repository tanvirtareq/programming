#include<bits/stdc++.h>

using namespace std;

struct data{
    string name;
    int height, weight;
    long long income;

};

bool compare(data a, data b)
{
    if(a.income==b.income)
    {
        if(a.height==b.height)
        {
            if(a.weight==b.weight)
            {
                return a.name.size()<b.name.size();

            }
            else return a.weight<b.weight;

        }
        else return a.height>b.height;

    }

    else return a.income>b.income;



}

int main()
{

    vector<pair<char, int> >v;

//    v.insert('c', 1);

    vector< vector< vector<char> > > v3;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int n;
            cin>>n;
            while(n--)
            {
                int a;
                cin>>a;
                v3[i][j].push_back(a);
            }
        }
    }

    return 0;
}
