#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int m, n; cin >> m >> n;
	vi s(n);
	int l = 1, r = 1;
	for (int i = 0;i < n;i++) {
		cin >> s[i];
		r = max(r, s[i]);
	}
	int ans = 0;
	while (l <= r) {
		int cnt = 0;
		int mid = (l + r) / 2;
		for (int i = 0;i < n;i++) {
			cnt += s[i] / mid;
		}
		if (cnt >= m) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}