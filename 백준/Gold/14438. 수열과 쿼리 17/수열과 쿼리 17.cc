#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define FASTIO cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

vll tree, arr;

void init(int node, int st, int ed) {
	if (st == ed) {// leaf node
		tree[node] = arr[st];
	}
	else {
		init(node * 2, st, (st + ed) / 2);// left child
		init(node * 2 + 1, (st + ed) / 2 + 1, ed);// right child
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

void update(int node, int st, int ed, int idx, ll val) {
	if (idx < st || idx > ed) return;
	if (st == ed) {
		tree[node] = val;
		return;
	}
	update(node * 2, st, (st + ed) / 2, idx, val);
	update(node * 2 + 1, (st + ed) / 2 + 1, ed, idx, val);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

ll query(int node, int st, int ed, int l, int r) {
	if (l > ed || r < st) return -1;
	if (l <= st && ed <= r) {
		return tree[node];
	}
	int lmin = query(node * 2, st, (st + ed) / 2, l, r);
	int rmin = query(node * 2 + 1, (st + ed) / 2 + 1, ed, l, r);
	if (lmin == -1) return rmin;
	else if (rmin == -1) return lmin;
	else return min(lmin, rmin);
}

int main() {
	FASTIO
	int n, m;
	cin >> n;
	arr = vll(n);
	tree = vll(4 * n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1,0,n-1);
	cin >> m;
	while (m--) {
		int key, a, b;
		cin >> key >> a >> b;
		if (key == 1) {
			update(1, 0, n-1, a-1, b);
		}
		else if (key == 2) {
			cout << query(1, 0, n - 1, a-1, b-1) << '\n';
		}
	}
}