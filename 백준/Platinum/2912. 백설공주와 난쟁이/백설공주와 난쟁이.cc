#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int sqrtN;

struct Query {
	int idx, s, e;

	bool operator < (Query& x) {
		if (s / sqrtN != x.s / sqrtN) return s / sqrtN < x.s / sqrtN;
		return e < x.e;
	}
};

int n, m, q;
vector<int> v;
vector<Query> query;
int ans[10101];
int cnt[10101];
int table[303030];
int res;

void Plus(int x) {
	cnt[x]++;
}

void Minus(int x) {
	cnt[x]--;
}
int solve(int k) {
	for (int i = 1;i <= m;i++) {
		if (k / 2 < cnt[i]) return i;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m; v.resize(n + 1); sqrtN = sqrt(n);
	for (int i = 1; i <= n; i++) cin >> v[i];
	cin >> q;
	for (int i = 0; i < q; i++) {
		int s, e; cin >> s >> e;
		query.push_back({ i, s, e });
	}
	sort(query.begin(), query.end());

	int s = 0, e = 0;
	res = 0;

	for (int i = 0; i < q; i++) {
		while (s < query[i].s) Minus(v[s++]);
		while (s > query[i].s) Plus(v[--s]);
		while (e < query[i].e) Plus(v[++e]);
		while (e > query[i].e) Minus(v[e--]);
		int k = query[i].e - query[i].s + 1;
		ans[query[i].idx] = solve(k);
	}

	for (int i = 0; i < q; i++) {
		if (ans[i]) cout << "yes " << ans[i] << '\n';
		else cout << "no\n";
	}
		
}