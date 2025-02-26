#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int arr[101][101];
bool visited[101][101];
int n;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };


void dfs(int x, int y, int k) {
	if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || arr[x][y]<=k) return;
	visited[x][y] = 1;
	for (int i = 0;i < 4;i++) {
		dfs(x + dx[i], y + dy[i], k);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) cin >> arr[i][j];
	}
	int ans = 0;
	for (int k = 0;k <= 100;k++) {
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (!visited[i][j] && arr[i][j]>k) {
					cnt++;
					dfs(i, j, k);
				}
			}	
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}