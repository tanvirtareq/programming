#include<bits/stdc++.h>

using namespace std;

bool iseq(string x, string y)
{
    if(x.size()<=1||y.size()<=1)
    {
        if(x==y) return 1;
        else return 0;
    }
    string x1, x2, y1, y2;

    x1.assign(x.begin(), x.begin()+x.size()/2);
    x2.assign(x.begin()+x.size()/2, x.begin()+x.size());
//    cout<<x1<<"  "<<x2<<endl;

    y1.assign(y.begin(), y.begin()+y.size()/2);
    y2.assign(y.begin()+y.size()/2, y.begin()+y.size());

//    cout<<y1<<" "<<y2<<endl;


    if((x1==y2||iseq(x1, y2))&&(x2==y1||iseq(x2, y1))) return 1;

    else return 0;

}
/**
abababababababababababababababababababababababababababababababababababababababab
babababababababababababababababababababababababababababababababababababababababa
*/

int main()
{
    string x1, x, y;
    while(cin>>x)
    {
        x1+=x;
    }
    x.assign(x1.begin(), x1.size()/2);
    y.assign(x1.begin()+x1.size()/2, x1.size());
//    cout<<x<<endl<<y<<endl;

    if(x==y||x.size()==0||y.size()==0) cout<<"YES"<<endl;

    else if(iseq(x, y)) cout<<"YES"<<endl;

    else  cout<<"NO"<<endl;

    return 0;
}

