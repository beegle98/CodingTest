#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int n, m, ans, digit=0;
bool btn[10];

void solve(int x, int cnt) {
    if (digit < cnt) {
        ans = min(ans, abs(x - n) + cnt);
        return;
    }
    if(cnt>0) ans = min(ans, abs(x - n) + cnt);
    for (int i = 0; i < 10; i++) {
        if (!btn[i]) {
            solve(x*10+i, cnt + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        btn[x] = 1;
    }
    int tmp = n;
    while (tmp) {
        tmp /= 10;
        digit++;
    }
    ans = abs(100 - n);
    solve(0, 0);
    cout << ans;
    return 0;
}