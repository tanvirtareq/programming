#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <set>
#include <string.h>
#include <queue>
#define MAX 1000000005
using namespace std;

map<int, int> mp;
map<int, int>::iterator it;
int a[100000];
int b[100000];

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n,l=0,m=0;
        cin >> n;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            mp[a]++;
        }
        for (it=mp.begin(); it!=mp.end(); it++) {
            b[l++]=it->first;
        }
        for (int i=1; i<l; i++) {
            if (abs(b[i-1]-b[i])==1) {
                a[m++]=mp[b[i-1]]+mp[b[i]];
            }
        }
        int ans=*max_element(a, a+m);
        cout << ans << endl;
        mp.clear();
    }
    return 0;
}
