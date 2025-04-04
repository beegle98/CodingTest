#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a, b; cin >> a >> b;

	while (a.size() < b.size()) {
		if (b.back() == 'B') {
			b.pop_back();
			reverse(b.begin(), b.end());
		}
		else if (b.back() == 'A') {
			b.pop_back();
		}
		else break;
	}

	if (a == b) cout << 1;
	else cout << 0;
	return 0;
}