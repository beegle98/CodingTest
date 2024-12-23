#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct Pos {
	int x, y, cnt;
	bool operator <(const Pos &o) const {
		if (this->cnt == o.cnt) {
			if (this->x == o.x) return this->y > o.y;
			return this->x > o.x;
		}
		return this->cnt > o.cnt;
	}
};

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int n;
int s[22][22];
pii st;

int bfs(int x,int y, int size) {

	int res = 0;
	priority_queue<Pos> pq;
	bool visited[22][22];
	memset(visited, false, sizeof(visited));
	visited[x][y] = true;
	pq.push({ x,y,0 });
	while (!pq.empty()) {
		Pos cur = pq.top();
		pq.pop();
		//cout << cur.x << ' ' << cur.y << ' ' << cur.cnt << '\n';
		if (s[cur.x][cur.y] != 0 && s[cur.x][cur.y] < size) {
			st.first = cur.x;
			st.second = cur.y;
			s[cur.x][cur.y] = 0;
			res += cur.cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || s[nx][ny] > size) continue;
			
			visited[nx][ny] = true;
			pq.push({ nx, ny, cur.cnt + 1 });
			
		}
	}
	return res;
}

void solve() {
	int size = 2;
	int cnt = 0,tmp;
	int ans = 0;
	while (tmp = bfs(st.first, st.second, size)) {
		//cout << st.first << ' ' << st.second << ' '<<tmp << ' ' << size << '\n';
		ans += tmp;
		cnt++;
		if (cnt == size) {
			cnt = 0;
			size++;
		}
	}
	cout << ans;
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
			if (s[i][j] == 9) {
				st.first = i;
				st.second = j;
				s[i][j] = 0;
			}
		}
	}
	solve();
	return 0;
}
