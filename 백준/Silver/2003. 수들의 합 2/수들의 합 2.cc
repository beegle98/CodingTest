#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m; cin >> n >> m;
	vll sum(n+1);
	unordered_map<ll, int> h;
	int ans = 0;
	h[0] = 1;
	for (int i = 1;i <= n;i++) {
		int x; cin >> x;
		sum[i] = sum[i-1] + x;
		ans += h[sum[i] - m];
		h[sum[i]]++;
	}
	cout << ans;

	return 0;
}