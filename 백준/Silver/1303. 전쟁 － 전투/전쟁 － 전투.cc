#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n, m;
string arr[100];
bool visited[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sumW, sumB;

int dfs(int x, int y, char c) {
	visited[x][y] = 1;
	int res = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || arr[nx][ny]!=c) continue;
		res += dfs(nx, ny, c);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) continue;
			if (arr[i][j] == 'W') {
				int sum = dfs(i, j, 'W');
				sumW += sum*sum;
			}
			else {
				int sum = dfs(i, j, 'B');
				sumB += sum*sum;
			}
		}
	}
	cout << sumW << " " << sumB;
	return 0;
}