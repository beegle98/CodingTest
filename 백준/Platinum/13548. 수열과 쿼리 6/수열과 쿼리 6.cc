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

int n, q;
vector<int> v;
vector<Query> query;
int ans[101010];
int cnt[101010];
int table[101010];
int res;

void Plus(int x) {
	if (cnt[x] != 0) table[cnt[x]]--;
	cnt[x]++; table[cnt[x]]++;
	res = max(res, cnt[x]);
}

void Minus(int x) {
	table[cnt[x]]--;
	if (cnt[x] == res && !table[cnt[x]]) res--;
	cnt[x]--;
	table[cnt[x]]++;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n; v.resize(n + 1); sqrtN = sqrt(n);
	for (int i = 1; i <= n; i++) cin >> v[i];
	cin >> q;
	for (int i = 0; i < q; i++) {
		int s, e; cin >> s >> e;
		query.push_back({ i, s, e });
	}
	sort(query.begin(), query.end());

	int s = 0, e = 0; res = 0;

	for (int i = 0; i < q; i++) {
		while (s < query[i].s) Minus(v[s++]);
		while (s > query[i].s) Plus(v[--s]);
		while (e < query[i].e) Plus(v[++e]);
		while (e > query[i].e) Minus(v[e--]);
		ans[query[i].idx] = res;
	}

	for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}