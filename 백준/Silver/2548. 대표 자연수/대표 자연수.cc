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
    vi s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end());
    int ans, Min=1e9, sum = 0;
    for (int i = 1; i <= 10000; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += abs(s[j] - i);
        }
        if (Min > sum) {
            Min = sum;
            ans = i;
        }
    }
    cout << ans;
    return 0;
}