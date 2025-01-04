#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N = 100001;
const int MOD = 1e9 + 7;

int tree[N*4], dp[12][N], arr[N];

void update(int node, int s, int e, int idx, int val){

    if (idx < s || idx > e) return;
    tree[node] += val;
    tree[node] %= MOD;
    if (s == e) return;
    int m = (s + e) / 2;
    update(node * 2, s, m, idx, val);
    update(node * 2 + 1, m + 1, e, idx, val);
}

int sum(int node, int s, int e, int l, int r) {
    if (l > e || r < s) return 0;
    if (l <= s && e <= r) return tree[node];
    int m = (s + e) / 2;
    return (sum(node * 2, s, m, l, r) + sum(node * 2 + 1, m + 1, e, l, r))%MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[1][i] = 1;
    }
    for (int i = 2; i <= k; i++) {
        memset(tree, 0, sizeof(tree));
        for (int j = 1; j <= n; j++) { 
            update(1, 1, n, arr[j], dp[i - 1][j]);
            dp[i][j] = sum(1, 1, n, 1, arr[j] - 1);
            dp[i][j] %= MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[k][i];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}