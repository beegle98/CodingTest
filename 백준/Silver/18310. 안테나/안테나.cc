#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    vi s(n);
    ll sum = 0, Min, ans;
    for (int i = 0; i < n; i++) cin >> s[i], sum += s[i];
    sort(s.begin(), s.end());
    Min = sum;
    int t = 0;
    for (int i = 0; i < n; i++) {
        int diff = s[i] - t;
        t = s[i];
        sum = sum + diff * i - diff * (n - i);
        if (Min > sum) {
            Min = sum;
            ans = s[i];
        }
    }
    cout << ans;
    
    return 0;
}