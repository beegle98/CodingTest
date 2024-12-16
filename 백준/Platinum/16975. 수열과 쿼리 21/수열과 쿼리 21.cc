#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N = 100001;
vll tree(4 * N);

void update(int node, int st, int ed, int idx, ll val) {
	if (idx < st || ed < idx) return;
	if (st == ed) {
		tree[node] += val;
		return;
	}
	update(node * 2, st, (st + ed) / 2, idx, val);
	update(node * 2 + 1, (st + ed) / 2 + 1, ed, idx, val);
	
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int st, int ed, int l, int r) {
	if (r < st || ed < l) return 0;
	if (l <= st && ed <= r) return tree[node];

	return query(node * 2, st, (st + ed) / 2, l, r) +
		query(node * 2 + 1, (st + ed) / 2 + 1, ed, l, r);
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n;	cin >> n;
	ll last = 0;
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		update(1, 1, n, i, x - last);
		last = x;
	}
	int m; cin >> m;
	while (m--) {
		int q; cin >> q;
		if (q == 1) {
			int i, j, k; cin >> i >> j >> k;
			update(1, 1, n, i, k);
			update(1, 1, n, j + 1, -k);
		}
		else if (q == 2) {
			int x; cin >> x;
			cout << query(1, 1, n, 1, x) << '\n';
		}

	}
	return 0;
}