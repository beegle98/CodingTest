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
		int num, a, b, c; cin >> num >> a >> b >> c;
		bool pass = 1;
		int sum = a + b + c;
		if (a <= 10 || b <= 7 || c < 12 || sum < 55) pass = 0;
		cout << num << " " << sum << " " << (pass ? "PASS" : "FAIL") << '\n';
	}
	return 0;
}