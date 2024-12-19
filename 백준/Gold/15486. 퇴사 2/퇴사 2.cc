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
    vector<pi> s;
    vi dp(n+1);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        s.push_back({ x,y });
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i + s[i].first <= n) dp[i] = s[i].second + dp[i + s[i].first];
        for(int j=i+1;j<min(i+s[i].first,n);j++){
            dp[i] = max(dp[i], dp[j]);
        }
    }
    cout << dp[0];
    return 0;
}