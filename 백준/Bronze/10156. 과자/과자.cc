#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k, n, m; cin >> k >> n >> m;
	if (k * n <= m) cout << "0";
	else cout << k * n - m;
	return 0;
}