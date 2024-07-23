#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, m, s[10][10], MIN=100, sum=0, cnt;
int virus[64][2], vlen = 0;
bool visited[10][10];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y) {
	visited[x][y] = 1;
	if (s[x][y] == 1) return;
	if (s[x][y] == 0) cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

void f(int x, int y, int k) {
	if (k == 3) {
		cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < vlen; i++) {
			dfs(virus[i][0], virus[i][1]);
		}
		MIN = min(MIN, cnt);
		return;
	}
	if (x >= n) return;
	int nx = x + (y + 1) / m;
	int ny = (y + 1) % m;
	if (s[x][y] == 0) {
		s[x][y] = 1;
		f(nx, ny, k+1);
		s[x][y] = 0;
	}
	f(nx, ny, k);
}

int main() {
	cin >> n >> m;
	
	sum = -3;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
			if (s[i][j] == 0) sum++;
			if(s[i][j]==2){
				virus[vlen][0] = i;
				virus[vlen++][1] = j;
			}
		}
	}
	f(0, 0, 0);
	cout << sum - MIN;
	return 0;
}
