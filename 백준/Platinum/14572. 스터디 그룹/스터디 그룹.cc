#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n, m, k, c[33];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    vector<pair<int, vector<int>>> v(n);
    for (auto& [x, y] : v) {
        int c; cin >> c >> x;
        y.resize(c);
        for (auto& x : y) cin >> x;
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0, j = -1; i < n; i++) {
        // 실력 차 K 이하로 유지
        while (j + 1 < n && v[j + 1].first - v[i].first <= k) {
            for (auto x : v[++j].second) c[x]++;
        }
        // E 계산
        int cnt = 0;
        for (int k = 1; k <= m; k++) if (c[k] && c[k] < j - i + 1) cnt++;
        ans = max(ans, cnt * (j - i + 1));
        // 맨 앞 포인터 그룹에서 제외
        for (auto x : v[i].second) c[x]--;
    }
    cout << ans;
	return 0;
}