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




int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned n;
    cin>>n;
    if(n==0)
    {
        cout<<10<<endl;
        return 0;
    }
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }

    mnpqi pq;
    string x;
//    pq.push(1+'0');

    for(unsigned i=9;i>1;i--)
    {
        while(n%i==0)
        {
            x.push_back((char)(i+'0'));
//            cout<<(char)(i+'0')<<endl;
//            cout<<i<<endl;
            n=n/i;
        }

    }

    if(n>10)
    {
        cout<<-1<<endl;
        return 0;
    }

    reverse(x.begin(), x.end());
    cout<<x<<endl;
//
//    while(pq.size()>=2)
//    {
////        cout<<(int)pq.top()<<endl;
//        int x=(int)(pq.top()-'0');
//        pq.pop();
//        unsigned y=pq.top()-'0';
//        pq.pop();
////        cout<<x<<endl;
//
//        if(x*y>=10)
//        {
//            pq.push(x+'0');
//            pq.push(y+'0');
//            break;
//        }
//        pq.push(x*y+'0');
//
//    }
//
//    while(!pq.empty()){
//        cout<<pq.top();
//        pq.pop();
//
//    }
//

	return 0;
}


