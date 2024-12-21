#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vi a(n+1), b(n+1), s(n+1), d(n+1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        d[i] = x;
        a[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        s[i] = a[x];
    }
    vi LIS, dp(n+1);
    dp[s[1]] = 0;
    LIS.push_back(s[1]);

    for (int i = 2; i <= n; i++) {
        if (LIS.back() < s[i]){
            dp[s[i]] = LIS.back();
            LIS.push_back(s[i]);
        }else{
            int itr = lower_bound(LIS.begin(), LIS.end(), s[i]) - LIS.begin();
            if (itr != 0) dp[s[i]] = LIS[itr - 1];
            LIS[itr] = s[i];
        }
    }
    cout <<LIS.size() << '\n';
    int k = LIS.back();
    vi ans;
    while (k) {
        //cout << k << ' ';
        ans.push_back(d[k]);
        k = dp[k];
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}