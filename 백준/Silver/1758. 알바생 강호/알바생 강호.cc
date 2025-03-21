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
	vi s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s.begin(), s.end(),greater<int>());
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] - i > 0) ans += s[i] - i;
		else break;
	}
	cout << ans;
	return 0;
}