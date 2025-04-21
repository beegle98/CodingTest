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
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 0; j < 5; j++) {
			int x; cin >> x;
			ans = max(ans, x);
		}
		cout << "Case #" << i << ": " << ans << '\n';
	}
	return 0;
}