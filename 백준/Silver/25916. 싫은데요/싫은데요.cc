#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int cnt[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vi cost(n);
    for (int i = 0; i < n; i++) cin >> cost[i];
    int s = 0, e = 0;
    ll sum = 0, ans = 0;
    while (e < n) {
        if (sum + cost[e] <= m) {
            sum += cost[e++];
            ans = max(ans, sum);
        }
        else sum -= cost[s++];
    }
    cout << ans;
    return 0;
}