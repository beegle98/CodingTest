#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const int N = 100001;
const ll INF = 1e12;
int n, m;
vi a(N);
vll Cost(N);
vector<pair<ll,int>> v[N];

void dijk(int st) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({ 0, st });
	Cost[st] = 0;
	while (!pq.empty()) {
		ll cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (Cost[cur] < cost) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			ll nCost = v[cur][i].first + cost;
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

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	a[n - 1] = 0;
	for (int i = 0; i < m; i++) {
		int x, y, d; cin >> x >> y >> d;
		if (a[x] == 1 || a[y] == 1) continue;
		v[x].push_back({ d, y });
		v[y].push_back({ d, x });
	}
	Cost.assign(n + 1, INF);
	dijk(0);
	int sum = 0, Max = 0;
	cout << (Cost[n - 1] == INF ? -1 : Cost[n - 1]) << '\n';
	
	return 0;
}
