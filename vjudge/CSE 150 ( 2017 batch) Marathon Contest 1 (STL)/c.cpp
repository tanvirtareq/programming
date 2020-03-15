#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, c=0, t, a2=0;
    cin>>n;

    int st=0, it=0, ni=0;
    string s, x, p, vp;
    vector<string>v;

    while(cin>>s)
        v.push_back(s);

    for(int i=0;i<v.size();i++)
    {
        s=v[i];
        if(s=="pair"&&p=="pair") ni++;
        else if(s=="pair"&&p!="pair") ni=2;
        else if(ni!=0&&s=="int")
        {
            ni--;
            c++;
        }
        else if(ni==0&&s=="int")
        {
            c++;
        }

        p=s;
//        cout<<"c="<<c<<" ni="<<ni<<endl;
    }
    t=0;
//    if(ni!=0) cout<<"Error occurred"<<endl;
    if(n!=c||ni!=0) cout<<"Error occurred"<<endl;

    else
    {
        for(int i=0;i<v.size();i++)
        {
            if(i!=0&&v[i]=="pair"&&v[i-1]=="pair")
            {
                cout<<v[i]<<"<";
                t++;
            }
            else if(i!=0&&v[i]=="pair"&&v[i-1]!="pair")
            {
                cout<<","<<v[i]<<"<";
                t=t+2;
                a2=1;
            }

            else if(i==0&&v[i]=="pair")
            {
                cout<<v[i];
                cout<<"<";
                t=2;
            }
            else if(t!=0&&v[i]=="int"&&v[i-1]=="pair")
            {
                cout<<v[i];
                t--;
            }
            else if(t!=0&&v[i]=="int"&&v[i-1]=="int")
            {
                cout<<","<<v[i]<<">";
                t--;
//                cout<<" t="<<t<<endl;
                int tmp=t;
                for(int i=1;i<=tmp;i++){
                        cout<<">";
                        t--;
                }


            }
            else if(t==0&&i!=0&&v[i]=="int")
            {
                cout<<","<<v[i];
            }
            else if(t==0&&i==0&&v[i]=="int")
            {
                cout<<v[i];
            }

        }

    }

    return 0;
}

/*
1
pair

2
pair pair

2
int int

2
pair pair int int int

4
pair int int pair int int

3
pair int int int

4
int pair int int int

6
pair int pair int pair int int int int

4
pair pair int int pair int int


*/
