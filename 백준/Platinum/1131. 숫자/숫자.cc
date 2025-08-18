#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

int a, b, k, p[10];
int dp[5000000];

int f(int n) {
	int ret = 0;
	while (n) ret += p[n % 10], n /= 10;
	return ret;
}

int dfs(int cur) { //cur_min
	int& ret = dp[cur];
	if (ret != 0 && ret != -1) return ret;
	else if (ret == 0) {
		ret = -1;
		ret = dfs(f(cur));
		return ret = min(ret, cur);
	}
	else if (ret == -1) {
		int mn = cur;
		for (int i = f(cur); i != cur; i = f(i)) mn = min(mn, i);
		for (int i = f(cur); i != cur; i = f(i)) dp[i] = mn;
		return ret = mn;
	}
}

void solve() {
	ll ans = 0;
	for (int i = a; i <= b; i++) {
		ans += dfs(i);
	}
	cout << ans << '\n';
}

void init() {
	cin >> a >> b >> k;
	dp[1] = 1;
	for (int i = 0; i < 10; i++) {
		p[i] = i;
		for (int j = 1; j < k; j++) p[i] *= i;
	}
}

int main() {
	init();
	solve();
	return 0;
}