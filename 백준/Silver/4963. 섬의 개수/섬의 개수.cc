#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n, m;
int arr[51][51];
bool visited[51][51];

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m 
		|| visited[x][y] == 1 || arr[x][y] == 0) return;
	visited[x][y] = 1;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			dfs(x+i, y+j);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> m >> n) {
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				visited[i][j] = false;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && arr[i][j]==1) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}