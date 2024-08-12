#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dp[3][111111];
const int MOD = 9901;
int main() {
	int n; cin >> n;
	int sum = 0;
	dp[0][1] = dp[1][1] = dp[2][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[0][i] = (dp[1][i - 1] + dp[2][i - 1]) % MOD;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i-1]) % MOD;
	}
	for (int i = 0; i < 3; i++) sum = (sum + dp[i][n])%MOD;
	cout << sum;
	return 0;
}
