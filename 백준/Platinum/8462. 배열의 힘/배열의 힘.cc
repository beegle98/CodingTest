#include <bits/stdc++.h>
#include <unordered_set>
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

int n, t;
vi v, table, cnt;
vll ans;
vector<Query> query;
ll res;

void Plus(int x) {
	cnt[x]++;
	ll a = cnt[x];
	res += (a * a - (a-1) * (a-1)) * x;
}

void Minus(int x) {
	cnt[x]--;
	ll a = cnt[x];
	res += (a * a - (a + 1) * (a + 1)) * x;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> t; sqrtN = sqrt(n); 
	v.resize(n + 1); ans.resize(t + 1); cnt.resize(1010101); table.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < t; i++) {
		int s, e; cin >> s >> e;
		query.push_back({ i, s, e });
	}
	sort(query.begin(), query.end());

	int s = 0, e = 0;
	res = 0;

	for (int i = 0; i < t; i++) {
		while (s < query[i].s) Minus(v[s++]);
		while (s > query[i].s) Plus(v[--s]);
		while (e < query[i].e) Plus(v[++e]);
		while (e > query[i].e) Minus(v[e--]);
		ans[query[i].idx] = res;
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}