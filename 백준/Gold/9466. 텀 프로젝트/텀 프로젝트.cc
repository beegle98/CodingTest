#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 100010;
const int NOT_VISITED = 0;
const int CYCLE = -1;

int n;
int arr[N];
int state[N];

void dfs(int x) {
	int cur = x;
	while (1) {
		state[cur] = x;
		cur = arr[cur]; // 다음 노드로
		// 이번 방문에서 지나간 노드 재방문
		if (state[cur] == x) {
			while (state[cur] != CYCLE) {
				state[cur] = CYCLE;
				cur = arr[cur];
			}
			return;
		}
		// 저번 방문에서 지나간 노드 재방문
		else if (state[cur] != NOT_VISITED) return;
	}
}

void solve() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		memset(state, 0, (n+1)*sizeof(int));
		for (int i = 1; i <= n; i++) {
			if (state[i] == NOT_VISITED) dfs(i);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (state[i] != CYCLE) cnt++;
		}
		cout << cnt << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}