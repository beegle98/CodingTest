#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vi s(n);
	for (int i = 0;i < n;i++) cin >> s[i];
	ll ans = 0, sum=0;
	for (int i = 0;i < m;i++) sum += s[i];
	ans = sum;
	for (int i = m;i < n;i++) {
		sum += s[i] - s[i - m];
		ans = max(ans, sum);
	}
	cout << ans;
	
	return 0;

}
