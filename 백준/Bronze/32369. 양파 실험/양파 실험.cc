#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, a, b, x=1, y=1;
	cin >> n >> a >> b;
	while (n-- > 0) {
		x += a;
		y += b;
		if (x < y) {
			int tmp = x;
			x = y;
			y = tmp;
		}
		else if (x == y) y--;
	}
	cout << x << " " << y;
	return 0;
}