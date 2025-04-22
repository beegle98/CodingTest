#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m, l; cin >> n >> m >> l;
	vi s(n+1);
	for (int i = 0;i < n;i++) cin >> s[i];
	s[n] = l;
	sort(s.begin(), s.end());
	int ans = 1000;
	for (int i = 1;i <= 1000;i++) {
		int prev = 0;
		int sum = 0;
		int diff;
		for (int j = 0;j <= n;j++) {
			diff = s[j] - prev;
			prev = s[j];
			sum += diff / i;
			if (diff % i == 0) sum--;
		}
		
		if (sum <= m) {
			ans = i;
			break;
		}
	}
	cout << ans;
	return 0;
}