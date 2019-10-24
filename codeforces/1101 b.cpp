#include<bits/stdc++.h>
#define pii pair<llu, llu>
#define inf ULLONG_MAX
//typedef pair<int, int> pii;
typedef long long unsigned llu;
typedef long long int lld;
using namespace std;

 string x;

//int dp(int pos, ib, ic, int v)
//{
//    if(ib==2 and ic==2)
//        return v;
//    if(pos>x.size())
//    {
//        return -1;
//    }
//
//    int v1=dp(pos+1, ib, ic, v-1);
//
//    int v2=0;
//
//    if()
//
//    if()
//
//}
//

int main()
{

    cin>>x;
    int ib=0, ic=0;

    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='[' and ib==0)
        {
            ib=1;
        }
        else if(x[i]=='[' and ib==1)
        {
            x.erase(x.begin()+i);
            i--;
        }

        else if(x[i]==':' and ib==1 and ic==0)
        {
            ic=1;
        }

        else if(ib==1 and ic==1)
            break;
        else{
            x.erase(x.begin()+i);
            i--;
        }

    }

    if(ib!=1 or ic!=1)
    {
        cout<<-1<<endl;
        return 0;
    }

//    cout<<x<<endl;

    ib=0;
    ic=0;

     for(int i=x.size()-1;i>=0;i--)
    {
        if(x[i]==']' and ib==0)
        {
            ib=1;
        }
        else if(x[i]==']' and ib==1)
        {
            x.erase(x.begin()+i);
//            i;
        }

        else if(x[i]==':' and ib==1 and ic==0)
        {
            ic=1;
        }

        else if(ib==1 and ic==1)
            break;
        else{
            x.erase(x.begin()+i);
//            i++;
        }

    }

//     if(ib!=1 or ic!=1)
//    {
//        cout<<-1<<endl;
//        return 0;
//    }

//    cout<<x<<endl;
    ib=0;
    ic=0;

    for(int i=0;i<x.size()-2;i++)
    {
        if(x[i]=='[' and ib==0)
        {
            ib=1;
        }
        else if(x[i]=='[' and ib==1)
        {
            x.erase(x.begin()+i);
            i--;
        }

        else if(x[i]==':' and ic==0)
        {
            ic=1;
        }

        else if(x[i]==':' and ic==1)
        {
            x.erase(x.begin()+i);
            i--;
        }

        else if(x[i]!='|')
        {
            x.erase(x.begin()+i);
            i--;
        }





    }

//    cout<<x<<endl;

    if(x.size()<=3)
            cout<<-1<<endl;

    else
        cout<<x.size()<<endl;


    return 0;
}
///  [|||::::|||||::::||||]
