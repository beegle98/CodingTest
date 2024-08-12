#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <cstdlib>

using namespace std;
pair<int, int> st, en;
int n, visited[301][301];
queue<pair<pair<int, int>,int>> q;

void bfs(int x,int y, int cnt) {
	if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] ) return;

	visited[x][y] = cnt;
	if (x == en.first && y == en.second) {
		while (!q.empty()) q.pop();
		return;
	}
	for (int i = -1; i <= 1; i+=2) {
		q.push({ {x + i,y + 2}, cnt + 1 });
		q.push({ {x + i,y - 2}, cnt + 1 });
	}
	for (int i = -2; i <= 2; i += 4) {
		q.push({ {x + i,y + 1}, cnt + 1 });
		q.push({ {x + i,y - 1}, cnt + 1 });
	}
}

int main() {
	int tc; cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> n;
		cin >> st.first >> st.second;
		cin >> en.first >> en.second;
		q.push({ {st.first,st.second},0 });
		while (!q.empty()) {
			pair<pair<int, int>, int> p = q.front();
			q.pop();
			bfs(p.first.first, p.first.second, p.second);
		}
		cout << visited[en.first][en.second] << '\n';
		memset(visited, 0, sizeof(visited));//
	}
	
	return 0;
}
