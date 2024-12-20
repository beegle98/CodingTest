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

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int ans=0, n; cin >> n;
        for (int j = 0; j < n; j++) {
            int c1, c2, r; cin >> c1 >> c2 >> r;
            int k = 0;
            if (((x1 - c1) * (x1 - c1) + (y1 - c2) * (y1 - c2)) < r * r) k++;
            if (((x2 - c1) * (x2 - c1) + (y2 - c2) * (y2 - c2)) < r * r) k++;
            if (k == 1) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}