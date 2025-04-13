#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll r, c, n; cin >> r >> c >> n;
	ll a = r / n + (r % n > 0 ? 1 : 0);
	ll b = c / n + (c % n > 0 ? 1 : 0);
	cout << a * b;
	return 0;
}