#include<bits/stdc++.h>

using namespace std;

map<string, int> wp;

string s;

int scan_str()
{
    char a, b='a';

    char ch;

    while(cin>>a)
    {
        if(a=='\n'||a=='\0'){cout<<"a="<<a<<endl<<"b="<<b<<endl;
        printf("a=%d    b=%d\n", a,b);

        return 0;}

        if(a=='\n'&&b!='\n'||a=='\0') {cout<<"a="<<a<<endl<<"b="<<b<<endl; return 1;}

        printf("a=%d    b=%d\n", a,b);

        s.push_back(a);

        b=a;
    }

}

int take_input()
{

    int cnt=0;

    while(1)
    {
       int c=scan_str();

       cnt++;

       cout<<"s="<<s<<endl;

       wp[s]++;

       if(c==0) return cnt;
    }

}

void output(map<string, int>mp, int total)
{
    map<string,  int>::iterator i;

    for(i=mp.begin();i!=mp.end();i++)
    {
        int a=i->second;

        float p=100*a/total;

        cout<<i->first<<" "<<fixed<<setprecision(4)<<a<<endl;

    }

    return;
}

int main()
{


    int t;

    cin>>t;

    cin.ignore();

    while(t--)
    {
        cout<<endl;

        wp.clear();

        int total=0;

        total =take_input();

//        output(wp, total);

        cout<<endl;

    }





    return 0;

}

