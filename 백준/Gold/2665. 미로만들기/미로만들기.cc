#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;


int dx[4] = { -1,0,1,0 }; // up, right, down, left
int dy[4] = { 0,1,0,-1 };
int n, ans=0;
deque<pii> dq;
string s[51];


void solve() {
	
	vector<vi> dp(n, vi(n, INT_MAX));
	dq.push_front({ 0,0 });
	dp[0][0] = 0;
	while (!dq.empty()) {
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

			int cnt = dp[x][y] + (s[nx][ny] == '0' ? 1 : 0);

			if (cnt < dp[nx][ny]) {
				dp[nx][ny] = cnt;
				if (s[nx][ny] == 0) {
					dq.push_back({ nx,ny });
				}
				else {
					dq.push_front({ nx,ny });
				}
			}
		}
	}
	cout << dp[n - 1][n - 1];
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '0') sum++;
		}
	}
	solve();
	return 0;
}
