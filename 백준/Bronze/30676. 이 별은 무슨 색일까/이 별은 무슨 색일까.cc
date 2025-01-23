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
    string ans;
    if (620 <= n && n <= 780) ans = "Red";
    else if (590 <= n) ans = "Orange";
    else if (570 <= n) ans = "Yellow";
    else if (495 <= n) ans = "Green";
    else if (450 <= n) ans = "Blue";
    else if (425 <= n) ans = "Indigo";
    else if (380 <= n) ans = "Violet";
    cout << ans;
    return 0;
}