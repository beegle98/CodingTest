#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const int N = 1000100;

vll tree(4 * N);

ll sum(int node, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[node];
	int m = (s + e) / 2;
	return sum(node * 2, s, m, l, r) + sum(node * 2 + 1, m + 1, e, l, r);
}

void update(int node, int s, int e, int idx, int diff) {
	if (idx < s || e < idx) return;
	if (s == e) {
		tree[node] = diff;
		return;
	}
	int m = (s + e) / 2;
	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int q, a, b; cin >> q >> a >> b;
		if (q == 0) {
			if (a > b) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			ll res = sum(1, 1, n, a, b);
			cout << res << '\n';
		}
		else if (q == 1) update(1, 1, n, a, b);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}