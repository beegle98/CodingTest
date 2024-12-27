#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
vll tree, arr;
ll lazy[404040][2];

ll init(int node, int s, int e){
    if(s == e){
        return tree[node] = arr[s];
    }
    int m = (s + e) / 2;
    return tree[node] = (init(node * 2, s, m) + init(node * 2 + 1, m + 1, e)) % MOD;
}

void update_lazy(int n, int s, int e) {
    if (lazy[n][0] == 1 && lazy[n][1] == 0) return;
    if (s != e) {
        lazy[n * 2][0] = (lazy[n * 2][0] * lazy[n][0]) % MOD;
        lazy[n * 2][1] = (lazy[n * 2][1] * lazy[n][0] + lazy[n][1]) % MOD;
        lazy[n * 2 + 1][0] = (lazy[n * 2 + 1][0] * lazy[n][0]) % MOD;
        lazy[n * 2 + 1][1] = (lazy[n * 2 + 1][1] * lazy[n][0] + lazy[n][1]) % MOD;
    }
    tree[n] = (lazy[n][0] * tree[n] + (e - s + 1) * lazy[n][1]) % MOD;
    lazy[n][0] = 1, lazy[n][1] = 0;
}

void update_range(int node, int s, int e, int l, int r, ll mul, ll plus) {
    update_lazy(node, s, e);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        lazy[node][0] *= mul; lazy[node][0] %= MOD;
        lazy[node][1] *= mul; lazy[node][1] %= MOD;
        lazy[node][1] += plus; lazy[node][1] %= MOD;
        update_lazy(node, s, e);
        return;
    }

    int m = s + e >> 1;
    update_range(node * 2, s, m, l, r, mul, plus);
    update_range(node * 2 + 1, m + 1, e, l, r, mul, plus);
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

ll query(int node, int s, int e, int l, int r) {
    update_lazy(node, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[node] % MOD;
    int m = (s + e) / 2;
    return (query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r)) % MOD;
}


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, m;
    cin >> n;
    arr = vll(n);
    tree = vll(4*n);
    for(int i=0;i<n;i++) cin >> arr[i];
    init(1,0,n-1);
    for (int i = 0; i < 404040; i++) lazy[i][0] = 1, lazy[i][1] = 0;
    cin >> m;
    

    for(int i=0;i<m;i++){
        int op; cin >> op;
        int a, b, c; cin >> a >> b;
        if (op != 4) cin >> c;
        if(op == 1) update_range(1, 0, n - 1, a - 1, b - 1, 1, c);
        else if (op == 2) update_range(1, 0, n - 1, a - 1, b - 1, c, 0);
        else if (op == 3) update_range(1, 0, n - 1, a - 1, b - 1, 0, c);
        else cout << query(1, 0, n - 1, a - 1, b - 1) << '\n';

    }
    
    return 0;
}