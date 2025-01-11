#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b, c; cin >> a >> b >> c;
	cout << a + b - c << '\n';
	int d = 1, tmp=b;
	while (tmp) {
		tmp /= 10;
		d *= 10;
	}
	cout << a * d + b - c << '\n';
	
	return 0;
}
