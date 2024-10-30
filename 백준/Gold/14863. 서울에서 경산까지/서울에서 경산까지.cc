#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int n, k;
vector<pi> v[2];
int ans = 0;

void solve(int idx, int cost, int sum) {
	if (cost > k) return;
	if (idx == n) {
		ans = max(ans, sum);
		return;
	}
	solve(idx + 1, cost + v[0][idx].first, sum + v[0][idx].second);
	solve(idx + 1, cost + v[1][idx].first, sum + v[1][idx].second);
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			int t, m; cin >> t >> m;
			v[j].push_back({ t,m });
		}
	}
	solve(0, 0, 0);
	cout << ans;
	return 0;
}

