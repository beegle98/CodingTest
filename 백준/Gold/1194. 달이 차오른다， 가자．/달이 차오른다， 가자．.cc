#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, m, ans=-1;
string s[55];
bool visited[55][55][65];

typedef struct MAP {
	int x;
	int y;
	int key;
	int cnt;
}map;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<MAP> q;

void dfs(int x, int y, int key, int cnt) {
	if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y][key]) return;

	visited[x][y][key] = true;

	if (s[x][y] == '1') {//탈출
		ans = cnt;
		while (!q.empty()) q.pop();
		return;
	}
	if (s[x][y] == '#') return;
	else if (s[x][y] >= 'a' && s[x][y] <= 'f') {
		key |= 1 << (s[x][y] - 'a');
		//cout << "a : " << key << "\n";
		for (int i = 0; i < 4; i++) {
			map tmp = { x + dx[i],y + dy[i],key,cnt + 1 };
			q.push(tmp);
		}
	}
	else if (s[x][y] >= 'A' && s[x][y] <= 'F') {
		//cout << (key & (1 << (s[x][y] - 'A'))) << '\n';
		if ((key & (1 << (s[x][y] - 'A'))) != 0) {
			for (int i = 0; i < 4; i++) {
				map tmp = { x + dx[i],y + dy[i],key,cnt + 1 };
					q.push(tmp);
			}
		}
	}
	else{
		for (int i = 0; i < 4; i++) {
			map tmp = { x + dx[i],y + dy[i],key,cnt + 1 };
			q.push(tmp);
		}
	}
}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '0') {
				map tmp = { i,j,0,0 };
				q.push(tmp);
			}
		}
	}
	while (!q.empty()) {
		map tmp = q.front();
		q.pop();
		dfs(tmp.x, tmp.y, tmp.key, tmp.cnt);
	}
	cout << ans;

	return 0;
}
