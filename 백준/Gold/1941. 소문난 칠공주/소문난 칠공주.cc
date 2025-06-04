#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const int N = 5;
char s[N][N];
bool selected[N][N];
bool visited[N][N];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sel[7];
int ans = 0;

bool check() {
	memset(visited, false, sizeof(visited));
	queue<pi> q;
	q.push({ sel[0] / N, sel[0] % N });
	visited[sel[0] / N][sel[0] % N] = 1;
	int sum = 1;
	while (!q.empty()) {
		//cout << sum << '\n';
		if (sum == 7) return true;
		pi cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N ||
				visited[nx][ny] || !selected[nx][ny]) continue;
			visited[nx][ny] = 1;
			sum++;
			//cout << nx << " " << ny << '\n';
			q.push({ nx, ny });
		}
	}
	return false;
}

void comb(int idx, int cnt, int depth) {
	if (depth == 7) {
		if (cnt >= 4 && check()) ans++;
		return;
	}
	if (idx >= N * N) return;
	int x = idx / N;
	int y = idx % N;
	sel[depth] = idx;
	selected[x][y] = 1;
	comb(idx + 1, s[x][y] == 'S' ? cnt + 1 : cnt, depth + 1);
	selected[x][y] = 0;
	comb(idx + 1, cnt, depth);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0;i < N;i++) {
		cin >> s[i];
	}
	comb(0, 0, 0);
	cout << ans;
	return 0;
}