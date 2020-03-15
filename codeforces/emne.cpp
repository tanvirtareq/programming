#include<bits/stdc++.h>
using namespace std;
#define ll long long

int num[1000005];

double mp[1000005];

int main() {
	int n;
	cin >> n;

	for(int i=1; i<=n; i++) cin >> num[i];

	cout << fixed << setprecision(15);

	ll sum = 0;
	set< pair<double, int> > st;
	for(int i=1; i<=n; i++) {
		sum += num[i];
		mp[i] = sum * 1.0 / i;
		st.insert({sum * 1.0 / i, i});
	}

	for(auto i : st) cout << i.first << ' ' << i.second << endl;
	int i=1;
	while(!st.empty() or i <= n) {
		auto now = *st.begin();

		ll sum = 0, cnt = 0;
		for(int j=i; j<=now.second; j++) {
			sum += num[j], cnt++;
			st.erase({mp[j], j});
		}
		for(int j=i; j<=now.second; j++) 
			cout << sum * 1.0 / cnt << endl;
		i = now.second + 1;
	}
}