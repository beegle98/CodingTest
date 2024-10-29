#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int s[51][51], sum[51][51], dp[51][51][51][51];

int solve(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2) return 0;
	if (dp[x1][y1][x2][y2]) return dp[x1][y1][x2][y2];
	
	int res = 1e9;
	for (int i = x1; i < x2; i++) {
		res = min(res, solve(x1, y1, i, y2) + solve(i + 1, y1, x2, y2));
	}
	for (int j = y1; j < y2; j++) {
		res = min(res, solve(x1, y1, x2, j) + solve(x1, j+1, x2, y2));
	}
	dp[x1][y1][x2][y2] = res + sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
	return dp[x1][y1][x2][y2];
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> s[i][j];
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i-1][j-1] + s[i][j];
		}
	}

	dp[1][1][n][m] = solve(1, 1, n, m);
	cout << dp[1][1][n][m];
	return 0;
}

