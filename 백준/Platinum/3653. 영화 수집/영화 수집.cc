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

int n, m;
vi arr, tree, idx;

int tree_init(int node, int s, int e) {
	if (s == e) return tree[node] = arr[s];
	int m = (s + e) / 2;
	return tree[node] = tree_init(node * 2, s, m) + tree_init(node * 2 + 1, m + 1, e);
}

void update(int node, int s, int e, int loc, int val) {
	if (s > loc || e < loc) return;
	if (s == e) {
		tree[node] = val;
		return;
	}
	int m = (s + e) / 2;
	update(node * 2, s, m, loc, val);
	update(node * 2 + 1, m + 1, e, loc, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tree[node];
	int m = (s + e) / 2;
	return tree[node] = query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}

void solve() {
	for (int i = 1; i <= m; i++) {
		int q; cin >> q;
		int ans = query(1, 1, n + m, idx[q]+1, n+m);
		cout << ans << ' ';
		update(1, 1, n + m, idx[q], 0);
		idx[q] = n + i;
		
		update(1, 1, n + m, idx[q], 1);
		
	}
	cout << '\n';
}

void init() {
	cin >> n >> m;
	arr = vi(n+m+10);
	tree = vi(4 * (n+m+10));
	idx = vi(n+10);
	for (int i = 1; i <= n; i++) {
		arr[i] = 1;
		idx[i] = n-i+1;
	}
	tree_init(1, 1, n+m);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		init();
		solve();
	}
	return 0;
}