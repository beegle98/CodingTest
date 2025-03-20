#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

struct Pos {
	int x;
	int y;
	int c;
	bool operator <(const Pos& o) const{
		return c > o.c;
	}
};

int n, m, x, y, t1, t2;
string s[301];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[301][301];
priority_queue<Pos> pq;
int ans = 1;

void bfs() {
	while (!pq.empty()) {
		Pos cur = pq.top();
		pq.pop();
		if (cur.x == t1 && cur.y == t2) {
			ans = cur.c;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
			visited[nx][ny] = 1;
			int nc = cur.c;
			if (s[nx][ny] != '0') nc++;
			pq.push({ nx, ny, nc });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	cin >> x >> y >> t1 >> t2;
	for (int i = 0; i < n; i++) cin >> s[i];
	x--; y--;
	t1--; t2--;
	pq.push({ x,y,0 });
	visited[x][y] = 1;
	bfs();
	cout << ans;
	return 0;
}
