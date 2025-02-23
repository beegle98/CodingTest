#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vll s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    int l = 0, r = n - 1;
    ll MIN = 1e12, ans[2];
    while (l < r) {
        ll sum = s[l] + s[r];
        if (abs(sum) < MIN) {
            MIN = abs(sum);
            ans[0] = s[l];
            ans[1] = s[r];
        }
        if (sum == 0) break;
        else if (sum < 0) l++;
        else r--;
    }
    cout << ans[0] << ' ' << ans[1];
    return 0;
}