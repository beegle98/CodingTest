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
    vi s(6);
    for (int i = 0; i < 6; i++) cin >> s[i];
    int t, p, a = 0, b, c;
    cin >> t >> p;
    for (int i = 0; i < 6; i++) {
        a += s[i] / t + ((s[i] % t) ? 1 : 0);
    }
    b = n / p;
    c = n % p;
    cout << a << '\n' << b << ' ' << c;
    return 0;
}