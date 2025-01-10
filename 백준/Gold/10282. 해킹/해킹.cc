#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const int N = 10001;
const int INF = 1e9;
vi Cost(N);
vector<pi> v[N];

void dijk(int st) {
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({ 0, st });
	Cost[st] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (Cost[cur] < cost) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int nCost = v[cur][i].first + cost;
			int next = v[cur][i].second;
			if (nCost < Cost[next]) {
				Cost[next] = nCost;
				pq.push({ nCost, next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for(int t=0;t<T;t++){
		int n, d, c; cin >> n >> d >> c;
		for (int i = 0; i < d; i++) {
			int a, b, s; cin >> a >> b >> s;
			v[b].push_back({ s, a });
		}
		Cost.assign(n+1, INF);
		dijk(c);
		int sum = 0, Max = 0;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			if (Cost[i] != INF) {
				Max = max(Max, Cost[i]);
				sum++;
			}
		}
		cout << sum << ' ' << Max << '\n';
	}
	return 0;
}
