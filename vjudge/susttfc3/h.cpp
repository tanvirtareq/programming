//#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<cmath>


using namespace std;

struct ch{
int nmbr;

ch *next;

};

void show(ch *frnt)
{
    cout<<frnt->nmbr<<endl;
    ch *nxt=frnt->next;

    while(nxt!=frnt)
    {
        cout<<nxt->nmbr<<endl;
        nxt=nxt->next;

    }
    return;

}

int delet(ch *frnt, int d)
{
    int ct=2;

    ch *nx=frnt->next;
    ch *prev=frnt;

    while(1)
    {
        if(ct==d)
        {
            if(prev==nx->next)
            {
                return prev->nmbr;
            }

            prev->next=nx->next;
            ct=1;
            nx=nx->next;

//            show(nx);
        }
        else
        {
            prev=nx;
            nx=nx->next;
            ct++;

        }

    }

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;


    while(cin>>n>>d)
    {
        if(n==0 and d==0) break;

        ch *prev=new ch();
        ch *frnt=prev;
        prev->nmbr=1;

        for(int i=2;i<=n;i++)
        {
            ch *nw=new ch();

            nw->nmbr=i;

            prev->next=nw;
            prev=nw;

        }

        prev->next=frnt;

//        show(frnt);

        cout<<delet(frnt, d)<<endl;

    }


    return 0;
}


