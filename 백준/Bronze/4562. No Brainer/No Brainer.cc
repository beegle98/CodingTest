#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		if (x >= y) cout << "MMM BRAINS\n";
		else cout << "NO BRAINS\n";
	}
	return 0;
}