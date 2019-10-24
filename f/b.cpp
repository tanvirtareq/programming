
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int q ,ar[100010],mx[10000], mnx=0, top=-1, tx=-1;

//    vector<int>v;
//    vector<int>:: iterator it;
//    priority_queue<int>p;
//    priority_queue<int>::iterator pit;
    scanf("%d", &q);
    while(q--)
    {
        int x;
        scanf("%d", &x);
        if(x==1)
        {
            int y;
            scanf("%d", &y);
            ar[++top]=y;
            if(mnx<=y)
            {
                mnx=y;
                mx[++tx]=mnx;
            }
//            cout<<top<<",,";
//            v.push_back(y);
//            p.push(y);
        }
        else if(x==2)
        {

//            if(!v.empty())
//            v.pop_back();
            if(top>=0)
            {
                if(mnx==ar[top])
                {
                    mnx=mx[--tx];
                }
                --top;
            }
//            cout<<top<<",,";
        }

        else
        {
//            cout<<top<<",,";
            cout<<mnx<<endl;

        }

    }

    return 0;
}
