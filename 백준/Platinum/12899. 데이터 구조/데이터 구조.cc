#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define FASTIO cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

vll tree, arr;


void update(int node, int st, int ed, int idx, int diff) {
	if (idx < st || idx > ed) return;
	if (st == ed) {
		tree[node] += diff;
		return;
	}
	update(node * 2, st, (st + ed) / 2, idx, diff);
	update(node * 2 + 1, (st + ed) / 2 + 1, ed, idx, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int st, int ed, int key) {
	if (st == ed) {
		return st;
	}
	if (tree[node * 2] >= key) return query(node * 2, st, (st + ed) / 2, key);
	else return query(node * 2 + 1, (st + ed) / 2 + 1, ed, key - tree[node * 2]);
}

int main() {
	FASTIO
	int n, m;
	n = 2000001;
	arr = vll(n);
	tree = vll(4 * n);

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			update(1, 0, n - 1, b, 1);
		}
		else if (a == 2) {
			int ans = query(1, 0, n - 1, b);
			cout << ans << '\n';
			update(1, 0, n - 1, ans, -1);
		}
	}
}