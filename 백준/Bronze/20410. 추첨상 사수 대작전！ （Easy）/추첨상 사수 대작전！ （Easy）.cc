#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

pair<ll, pair<ll, ll>> xGCD(ll a, ll b) { // returns {g, {x, y}}, ax+by=g
	if (b == 0) return { a,{1,0} }; // base case
	pair<ll, pair<ll, ll>> ret = xGCD(b, a % b);
	ll g, x, y;
	g = ret.first;
	tie(x, y) = ret.second;
	return { g,{y,x - (a / b) * y} };
}

ll f(ll x, ll n, ll mod) {
	if (n == 0) return 1;
	if (n == 1) return x % mod;
	if (n % 2 == 0) {
		ll res = f(x, n / 2, mod) % mod;
		res = res * res;
		return res % mod;
	}
	else {
		ll res = f(x, n / 2, mod) % mod;
		res = (res * res) % mod;
		return (x * res) % mod;
	}
}
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll m, seed, x1, x2; cin >> m >> seed >> x1 >> x2;
    ll a, c;
    if (x1 == seed) {
        a = 0, c = x1;
    }
    else {
        a = (x2 - x1) % m;
        a = a < 0 ? a + m : a;
        a = (a * f(x1 - seed < 0 ? x1 - seed + m : x1 - seed, m - 2, m)) % m;
        c = (x2 - a * x1) % m;
        c = c < 0 ? c + m : c;
    }
    cout << a << ' ' << c;
    return 0;
}