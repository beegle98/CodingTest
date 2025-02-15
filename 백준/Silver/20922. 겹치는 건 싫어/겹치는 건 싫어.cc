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
    int n, k; cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int s = 0, e = 0;
    ll ans = 0;
    while (e < n) {
        if (cnt[arr[e]] < k) cnt[arr[e++]]++;
        else cnt[arr[s++]]--;
        ans = max(ans, ll(e - s));
    }
    cout << ans;
    return 0;
}