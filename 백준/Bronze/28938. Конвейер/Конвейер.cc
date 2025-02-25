#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ans=0; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) ans++;
        else if (x == -1) ans--;
    }
    if (ans > 0) cout << "Right";
    else if (ans == 0) cout << "Stay";
    else cout << "Left";
    return 0;
}