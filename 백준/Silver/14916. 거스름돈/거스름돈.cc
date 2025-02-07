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
    int r = n / 5, q = n % 5;
    if (q % 2 == 0) cout << r + q / 2;
    else if (q + 5 > n) cout << "-1";
    else cout << r - 1 + (q + 5) / 2;
    return 0;
}