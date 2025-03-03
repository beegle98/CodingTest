#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, h; cin >> n >> h;
    vi up(h+1), down(h+1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (i % 2 == 0) down[x]++;
        else up[h - x + 1]++;
    }
    for (int i = 1; i <= h; i++) {
        up[i] += up[i - 1];
        down[h - i] += down[h - i + 1];
    }
    int ans = 1e9, cnt=0;
    for (int i = 1; i <= h; i++) {
        int sum = down[i] + up[i];
        if (sum == ans) cnt++;
        else if (sum < ans) {
            cnt = 1;
            ans = sum;
        }
    }
    cout << ans << " "<< cnt;
    return 0;
}