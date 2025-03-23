#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	unordered_map<string, int> h;
	vector<string> in(n), out(n);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		h[in[i]] = i;
	}
	for (int i = 0; i < n; i++) cin >> out[i];
	int MIN = 10000, cnt=0;
	for (int i = n - 1; i >= 0; i--) {
		if (MIN > h[out[i]]) MIN = h[out[i]];
		else cnt++;
	}
	cout << cnt;
	return 0;
}