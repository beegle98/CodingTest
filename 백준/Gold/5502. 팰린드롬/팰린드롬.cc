#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;

using namespace std;

const int N = 5005;
int n;
string s;
int dp[N][N];
int solve(int l, int r) {
	if (l > r || l == r) return 0;
	if (s[l] == s[r]) {
		return dp[l][r] = solve(l + 1, r - 1);
	}
	if (l + 1 == r) return 1;
	if (dp[l][r] != -1) return dp[l][r];
	
	return dp[l][r] = 1 + min(solve(l+1,r),solve(l,r-1));
}
int main() {

	cin >> n;
	cin >> s;
	memset(dp, -1, sizeof(dp));
	int ans = solve(0, n - 1);
	cout << ans;
	return 0;
}