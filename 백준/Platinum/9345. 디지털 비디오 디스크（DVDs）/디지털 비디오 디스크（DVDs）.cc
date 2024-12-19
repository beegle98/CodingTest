#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const int N = 100001;
const ll INF = 1e12;
vector<pll> tree(4 * N);
vll arr(N);

void update(int node, int st, int ed, int idx, ll val) {
	if (idx < st || ed < idx) return;
	if (st == ed) {
		tree[node].first = val;
		tree[node].second = val;
		return;
	}
	update(node * 2, st, (st + ed) / 2, idx, val);
	update(node * 2 + 1, (st + ed) / 2 + 1, ed, idx, val);
	
	tree[node].first = min(tree[node * 2].first, tree[node * 2 + 1].first);
    tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
}

ll min_query(int node, int st, int ed, int l, int r) {

	if (r < st || ed < l) return INF;
	if (l <= st && ed <= r) return tree[node].first;

	return min(min_query(node * 2, st, (st + ed) / 2, l, r),
		min_query(node * 2 + 1, (st + ed) / 2 + 1, ed, l, r));
}

ll max_query(int node, int st, int ed, int l, int r) {

	if (r < st || ed < l) return 0;
	if (l <= st && ed <= r) return tree[node].second;

	return max(max_query(node * 2, st, (st + ed) / 2, l, r),
		max_query(node * 2 + 1, (st + ed) / 2 + 1, ed, l, r));
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int T;	cin >> T;
    for (int i = 0; i < T; i++){
        int n, k; cin >> n >> k;
        for (int j = 0; j < n; j++){
            arr[j]=j;
            update(1,0,n-1,j,arr[j]);
        }
        tree.clear();
        while(k--){
            int op, a, b; cin >> op >> a >> b;
            if(op==0){
                int tmp = arr[a];
                arr[a] = arr[b];
                arr[b] = tmp;
                update(1,0,n-1,a,arr[a]);
                update(1,0,n-1,b,arr[b]);
            }else{
                int m1 = min_query(1,0,n-1,a,b);
                int m2 = max_query(1,0,n-1,a,b);
                //cout << m1 << " " << m2 << endl;
                if(m1==a && m2==b) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
	return 0;
}