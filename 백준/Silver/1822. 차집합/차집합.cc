#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	set<int> h;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		h.insert(x);
	}
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		h.erase(x);
	}
	
	cout << h.size() << '\n';
	for (int a : h) {
		cout << a << ' ';
	}
	
	
	return 0;
}