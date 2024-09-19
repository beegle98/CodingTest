#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 100000;
int dp[N][2];
int main() {
	int n,ans; cin >> n;
	cin >> dp[0][0];
	ans = dp[0][0];
	for (int i = 1; i < n; i++) {
		int x; cin >> x;
		dp[i][0] = max(x, dp[i - 1][0] + x);
		dp[i][1] = max(dp[i - 1][1] + x, dp[i - 1][0]);
		ans = max(ans, dp[i][0]);
		ans = max(ans, dp[i][1]);
	}
	cout << ans;
	return 0;
}