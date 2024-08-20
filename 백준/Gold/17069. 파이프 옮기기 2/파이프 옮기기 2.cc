#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

ll s[40][40], dp[40][40][3];//x,y,모양 (가로:0, 세로:1, 대각선:2)

int main()
{
	FASTIO
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	dp[1][2][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i][j] == 1) continue;
			dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
			dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
			if (s[i - 1][j] == 0 && s[i][j - 1] == 0) {
				for (int k = 0; k < 3; k++) dp[i][j][2] += dp[i - 1][j - 1][k];
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < 3; i++) {
		ans += dp[n][n][i];
	}
	cout << ans;
	return 0;
}