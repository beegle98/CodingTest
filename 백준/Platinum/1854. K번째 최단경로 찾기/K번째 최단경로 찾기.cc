#include <iostream> // 시간초과
#include <algorithm>
#include <vector>
#include <queue>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int INF = 1e9;
const int N = 1000;
struct Pos {
	int idx;
	int cost;

	bool operator < (const Pos& t) const {
		return cost > t.cost;
	}
};

vector<Pos> MAP[N + 1];
priority_queue<int> Cost[N + 1];
int n, m, k;
void dijk(Pos start) {

	priority_queue<Pos> pq;
	pq.push(start);

	while (!pq.empty()) {

		Pos now = pq.top();
		pq.pop();

		for (int i = 0; i < MAP[now.idx].size(); i++) {
			Pos next = MAP[now.idx][i];
			int nCost = now.cost + next.cost;

			if (Cost[next.idx].size() < k) {
				Cost[next.idx].push(nCost);
				pq.push({ next.idx,nCost });
			}else if (Cost[next.idx].size() == k && Cost[next.idx].top() > nCost) {
				Cost[next.idx].pop();
				Cost[next.idx].push(nCost);
				pq.push({ next.idx,nCost });
			}
			
		}
	}
}

int main() {
	FASTIO

		cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		MAP[a].push_back({ b,c });
	}
	Cost[1].push(0);
	dijk({ 1,0 });

	for (int i = 1; i <= n; i++) {
		if (Cost[i].size() < k) cout << "-1\n";
		else cout << Cost[i].top() << '\n';
	}

	return 0;
}
