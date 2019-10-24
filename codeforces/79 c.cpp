#include<bits/stdc++.h>


using namespace std;

vector<pair<int, int> > v, v1;

void find_lps(string pattern, int lps[])
{
    int i=1, j=0;

    lps[0]=0;

    while(i<pattern.size())
    {
        if(pattern[i]==pattern[j])
        {
            j++;

            lps[i]=j;
            i++;
        }

        else if(j!=0)
        {
            j=lps[j-1];
        }

        else
        {
            lps[i]=0;
            i++;
        }

    }
    return ;
}

int kmpSearch(string text, string pattern, int lps[])
{
    int i=0, j=0, numberOfOccurance=0;

    while(i<text.size())
    {

        if(text[i]==pattern[j])
        {
            i++;
            j++;

            if(j>=pattern.size())
            {
                numberOfOccurance++;
                v.push_back(make_pair(i-pattern.size()  ,i-1));

                j=lps[j-1];

//                cout<<j<<" "<<i<<endl;

            }


        }

        else if(j!=0)
        {
            j=lps[j-1];

        }
        else i++;



    }

    return numberOfOccurance;


}

bool cmp(pair<int, int>  p1, pair<int, int> p2)
{
    if(p1.first<p2.first) return true;

    if(p1.first==p2.first)
    {
        if(p1.second>p2.second) return true;

        else return false;
    }

    else return false;

}

void show(vector<pair<int, int> > x)
{
    for(int i=0;i<x.size();i++)
    {
        cout<<x[i].first<<" "<<x[i].second<<endl;

    }
    cout<<endl;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text;

    cin>>text;

    int n;


    cin>>n;

    while(n--)
    {
        string pat;
        cin>>pat;

        int lps[pat.size()+10];

        find_lps(pat, lps);

        kmpSearch(text, pat, lps);

    }

    if(v.size()==0)
    {
        cout<<text.size()<<" "<<0<<endl;
        return 0;
    }

//    cout<<"r"<<endl;

    sort(v.begin(),v.end(), cmp);

//    show(v);

//    cout<<"r"<<endl;

    stack<pair<int, int> > st;

    st.push(v[0]);

    for(int i=1;i<v.size();i++)
    {
        while(!st.empty() and st.top().second>v[i].second)
        {
//            cout<<st.top().second<<endl;
            st.pop();
        }

//        cout<<"r"<<endl;
        st.push(v[i]);

    }

//    cout<<"r"<<endl;

    while(!st.empty())
    {
        v1.push_back(st.top());
        st.pop();

    }

    sort(v1.begin(), v1.end(), cmp);

//    cout<<"r"<<endl;

    v1.push_back(v[v.size()-1]);

//    show(v1);

    int mx=0;

    mx=v1[0].second;

    int pos=0;

    for(int i=0;i<v1.size()-1;i++)
    {
        int x=v1[i+1].second-1-(v1[i].first+1)+1;

//        cout<<v1[i+1].second-1<<" "<<v1[i].first+1<<endl;

        if(x>mx)
        {
//            cout<<mx<<" "<<pos<<endl;

            mx=x;
            pos=v1[i].first+1;
        }

    }

    int x=text.size()-(v1[v1.size()-1].first+1);

//    cout<<text.size()<<" "<<v1[v1.size()-1].first+1<<endl;

    if(x>mx){
    pos=v1[v1.size()-1].first+1;
    mx=x;
    }

    cout<<mx<<" "<<pos<<endl;



    return 0;
}

/**

Go_straight_along_this_street
5
str
long
tree
biginteger
ellipse


iiiiii
10
ii
iiii
iiiii
iii
iiii
5avjcwIsDh
GgiVQ9ylRz
ewWmNAJAL9
k83baq5H2U
XRX3fJ4dH8

YUYEYEUUEU
10
YEYEUUEU
EUUE
UU
YEYEUUE
YEYE
UU
EY
EYEUU
YEYEUU
iBXoTbQ7X3

*/
