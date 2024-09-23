#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
const int N = 2001;

vector<int> v[N];
bool visited[N];
int ans = 0;

void dfs(int cur,int cnt) {
	if (cnt == 5) {
		ans = 1;
		return;
	}
	for (int i = 0; i < v[cur].size(); i++) {
		if (visited[v[cur][i]]) continue;
		visited[v[cur][i]] = 1;
		dfs(v[cur][i], cnt + 1);
		visited[v[cur][i]] = 0;
	}
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int j = 0; j < n; j++) {
		if (ans) break;
		visited[j] = 1;
		dfs(j, 1);
		visited[j] = 0;
	}
	cout << ans;
	return 0;
}
