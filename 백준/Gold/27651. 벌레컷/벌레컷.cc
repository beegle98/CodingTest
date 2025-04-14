#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vi a(n + 1);
	vll sum(n);
	cin >> a[0]; sum[0] = a[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	ll ans = 0;
	for (int i = n-2; i >= 1; i--) {
		ll val = sum[i] - (sum[n-1] - sum[i]);
		int r = lower_bound(sum.begin(), sum.end(), val) - sum.begin();
		val = sum[n-1] - sum[i];
		int l = lower_bound(sum.begin(), sum.end(), val) - sum.begin();
		ans += min(r, l);
	}
	cout << ans;
	return 0;
}