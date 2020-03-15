#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<char, vector<char> , greater<char> > mnpqi;


int fact(int x)
{
    if(x<=1) return 1;
    return x*fact(x-1);
}

int nmbr(string x, int sec[],int k)
{
    int nmbr=0;
    int c=1;
//    cout<<nmbr<<endl;
    for(int i=k-1;i>=0;i--)
    {
        nmbr+=c*(x[sec[i]]-'0');
//        cout<<x[i]<<endl;
        c*=10;

    }
//    cout<<endl;
    return nmbr;

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    int sec[n];
    for(int i=0;i<k;i++)
        sec[i]=i;

    string x[n+10];
    string str="asdf";
//    next_permutation(str.begin(), str.end());

    for(int i=1;i<=n;i++)
    {
        cin>>x[i];

    }
//    cout<<x[1]<<endl;

    int sml=INT_MAX;
    int lrg=0;
    int p=INT_MAX;
    int pf=fact(k);
//    cout<<pf<<endl;
    int ct=0;
    do{
        ct++;
        sml=INT_MAX;
        lrg=0;

        for(int i=1;i<=n;i++)
        {
            int f=nmbr(x[i], sec, k);
//            cout<<f<<endl;
            if(f<sml) sml=f;
            if(lrg<f) lrg=f;
        }
        if(p>lrg-sml) p=lrg-sml;

//        cout<<lrg<<" "<<sml<<endl;
//        cout<<p<<endl;

//        for(int i=1;i<=n;i++)


//    cout<<endl;

    }while(next_permutation(sec, sec+k));

    cout<<p<<endl;


	return 0;
}



