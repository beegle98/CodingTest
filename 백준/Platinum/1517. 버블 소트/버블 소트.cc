#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const int N = 500001;
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
	vector<pi> s;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        s.push_back({x, i});
    }
    sort(s.begin(), s.end());
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += query(1, 0, n-1, s[i].second, n-1);
        update(1, 0, n-1, s[i].second, 1);
    }
    cout << ans;
	return 0;
}