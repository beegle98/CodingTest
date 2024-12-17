#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N = 1<<16+1;

vll tree(4 * N);

void update(int node, int st, int ed, int idx, int val) {
    if (idx < st || ed < idx) return;
    if (st == ed) {
        tree[node] += val;
        return;
    }
    update(node * 2, st, (st + ed) / 2, idx, val);
    update(node * 2 + 1, (st + ed) / 2 +1, ed, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int st, int ed, int key) {
    if (st == ed) {
        return st;
    }
    if (tree[node * 2] >= key) return query(node * 2, st, (st + ed) / 2, key);
    else return query(node * 2 + 1, (st + ed) / 2 + 1, ed, key - tree[node * 2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;  cin >> n >> k;
    vll arr(n+1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (i < k) {
            update(1, 0, N - 1, arr[i], 1);
        }
        else {
            update(1, 0, N - 1, arr[i], 1);
            ans += query(1, 0, N - 1, (k+1)/2);
            update(1, 0, N - 1, arr[i - k + 1], -1);
        }
    }
    cout << ans;
    return 0;
}