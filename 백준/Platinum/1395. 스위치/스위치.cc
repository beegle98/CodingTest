#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N = 1001000;

vll tree(4 * N), lazy(4 * N);


void update_lazy(int node, int start, int end) {
    if (lazy[node]%2 == 1) {
        tree[node] = (end - start + 1) - tree[node];
        if (start != end) {
            lazy[node * 2]++;
            lazy[node * 2 + 1]++;
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);

    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        tree[node] = (end - start + 1) - tree[node];
        if (start != end) {
            lazy[node * 2]++;
            lazy[node * 2 + 1]++;
        }
        return;
    }
    update_range(node * 2, start, (start + end) / 2, left, right);
    update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll sum(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) {
        return tree[node];
    }
    return sum(node * 2, start, (start + end) / 2, left, right)
        + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;  cin >> n >> m;
    
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {// update
            update_range(1, 1, n, b, c);
        }
        else {// sum
            cout << sum(1, 1, n, b, c) << '\n';
        }
    }

    return 0;
}