#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int l, r; cin >> l >> r;
	string a, b;
	a = to_string(l);
	b = to_string(r);
	int ans = 0;
	if(a.size()==b.size()) {
		for (int i = 0;i < a.size();i++) {
			if (a[i] != b[i]) break;
			else if (a[i] == '8') ans++;
		}
	}
	cout << ans;
	return 0;
}