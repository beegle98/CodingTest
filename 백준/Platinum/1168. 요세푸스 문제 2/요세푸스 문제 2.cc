#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define FASTIO cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

vll tree;

void init(int node, int st, int ed) {
	if (st == ed) {
		tree[node] = 1;
		return;
	}
	init(node * 2, st, (st + ed) / 2);
	init(node * 2 + 1, (st + ed) / 2 + 1, ed);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

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
	int n, k;
	cin >> n >> k;
	tree = vll(4 * n);
	init(1, 0, n-1);
	
	vi ans;
	int idx = 1;
	for (int i = n; i > 0; i--) {
		idx = (idx + k-1) % i;
		if (idx == 0) idx = i;
		int res = query(1, 0, n - 1, idx);
		ans.push_back(res+1);
		update(1, 0, n - 1, res, -1);
	}
	cout << "<";
	for (int i = 0; i < ans.size()-1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans[n - 1] << ">";
	return 0;
}