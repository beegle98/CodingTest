#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const int N = 1000100;

vll tree, arr;

ll init(int node, int s, int e){
    if (s == e) return tree[node] = arr[s]; //리프 노드
    int m = (s + e) / 2;
    return tree[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}

ll sum(int node, int s, int e, int l, int r) {
    if (l > e || r < s) return 0; // 범위 밖
    if (l <= s && e <= r) { // 범위 안
        return tree[node];
    }
    int m = (s + e) / 2;
    return sum(node * 2, s, m, l, r)
        + sum(node * 2 + 1, m + 1, e, l, r);
}

void update(int node, int s, int e, int idx, ll val) {
    if (idx < s || idx > e) return; // 범위 밖
    if (s == e) { // idx 찾음
        tree[node] = val;
        return;
    }
    int m = (s + e) / 2;
    update(node * 2, s, m, idx, val);
    update(node * 2 + 1, m + 1, e, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    tree = vll(4 * N);
    arr = vll(N);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        //update(1, 1, n, i, arr[i]);
    }
    init(1, 1, n);

    for (int i = 0; i < m + k; i++) {
        int op; cin >> op;
        if (op == 1) {// update
            ll a, b; cin >> a >> b;
            update(1, 1, n, a, b);
        }
        else if (op == 2) {// sum
            ll a, b; cin >> a >> b;
            cout << sum(1, 1, n, a, b) << '\n';
        }
    }

    return 0;
}