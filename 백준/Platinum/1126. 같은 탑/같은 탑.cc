#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int MAX = 5e5;
int n,dp[50][MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    dp[0][a[0]] = a[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= MAX; ++j) {
            if (dp[i - 1][j] == -1) continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j + a[i] <= MAX) dp[i][j + a[i]] = max(dp[i][j + a[i]], dp[i - 1][j] + a[i]);
            if (a[i] < j) {
                dp[i][j - a[i]] = max(dp[i][j - a[i]], dp[i - 1][j]);
            }
            else {
                dp[i][a[i] - j] = max(dp[i][a[i] - j], dp[i - 1][j] + a[i] - j);
            }
        }
    }
    cout << (dp[n - 1][0] > 0 ? dp[n - 1][0] : -1);
    return 0;
}