#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

struct T { int k; int i; int j; int idx; };

vll tree;

void update(int node, int st, int ed, int idx, int val) {
    if (idx < st || ed < idx) return;
    if (st == ed) {
        tree[node] = val;
        return;
    }
    update(node * 2, st, (st + ed) / 2, idx, val);
    update(node * 2 + 1, (st + ed) / 2 +1, ed, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int st, int ed, int l, int r) {
    if (l > ed || r < st) return 0;
    if (l <= st && ed <= r) return tree[node];
    return query(node * 2, st, (st + ed) / 2, l, r) +
        query(node * 2 + 1, (st + ed) / 2 + 1, ed, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;  cin >> n;
    tree = vll(4 * n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        update(1, 0, n - 1, i, x);
    }
    vector<pi> a;
    vector<T> b;
    cin >> m;
    vll ans(m);
    int idx = 0;
    while (m--) {
        int c; cin >> c;
        if (c == 1) {
            int x, y; cin >> x >> y;
            a.push_back({ x-1,y });
        }
        else {
            int k, i, j; cin >> k >> i >> j;
            b.push_back({ k,i-1,j-1,idx++ });
        }
    }
    sort(b.begin(), b.end(), [](T& a, T& b) {
        return a.k < b.k;
    });

    int t=0;
    for (int i = 0; i < a.size(); i++) {
        while (b[t].k == i) {
            ans[b[t].idx] = query(1, 0, n - 1, b[t].i, b[t].j);
            t++;
        }
        update(1, 0, n-1, a[i].first, a[i].second);
    }
    for (int i = t; i < b.size(); i++) ans[b[i].idx] = query(1, 0, n - 1, b[i].i, b[i].j);
    for (int i = 0; i < b.size(); i++) cout << ans[i] << '\n';
    return 0;
}