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
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;




int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long n;

    cin >> t;
    while(t --){
        cin >> n;
        int f = !(n & 1);
        for(int i = 2; i < 50; i += 2)
            if(n & (1LL << i)){
                f = 1;
                break;
            }
        if(f == 0)
            cout << "Ivica" << endl;
        else cout << "Marica" << endl;
    }
	return 0;
}

