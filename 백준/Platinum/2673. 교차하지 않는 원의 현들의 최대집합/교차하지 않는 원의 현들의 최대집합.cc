#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int dp[101][101], cost[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cost[x][y] = cost[y][x] = 1;
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = i; j >= 1; j--) {
            for (int k = j; k < i; k++) {
                dp[j][i] = max(dp[j][i], dp[j][k] + dp[k][i] + cost[j][i]);
            }
        }
    }
    cout << dp[1][100];
    return 0;
}