#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, sum =0; cin >> n >> k;
    vi idx;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) idx.push_back(i);
    }
    int ans = 1e9;
    if (idx.size() < k) ans = -2;
    else {
        for (int i = 0; i <= idx.size() - k; i++) {
            ans = min(ans, idx[i + k - 1] - idx[i]);
        }
    }
    cout << ans+1;
    return 0;
}