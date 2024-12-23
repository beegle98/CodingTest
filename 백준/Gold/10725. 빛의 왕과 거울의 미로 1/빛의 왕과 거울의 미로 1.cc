#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct Node {
	int x, y, dir;
};

const int MOD = 10007;
int dx[4] = { -1,0,1,0 }; // up, right, down, left
int dy[4] = { 0,1,0,-1 };
int n, m;
char s[10][10];
bool visited[10][10][4];
Node st, ed;
int ans = 0;
vector<pii> pos;

void f(int k, Node &ptr, int op) { // op = ed의 경우 방향 반대로 해주는 옵션
	if (1 <= k && k <= m) { // down
		ptr.dir = 2;
		ptr.x = 1;
		ptr.y = k;
	}
	else if(m+1<=k && k<=m+n) { // right
		ptr.dir = 1;
		ptr.x = k-m;
		ptr.y = 1;
	}
	else if (m + n + 1 <= k && k <= m + 2*n) { // left
		ptr.dir = 3;
		ptr.x = k-m-n;
		ptr.y = m;
	}
	else { // up
		ptr.dir = 0;
		ptr.x = n;
		ptr.y = k-m-2*n;
	}
	ptr.dir = (ptr.dir + op) % 4;
}
int getDir(int dir, char c) {
	if (c == '\\') {
		dir = 3 - dir;
	}
	else if (c == '/'){
		if (dir % 2) dir--;
		else dir++;
	}
	return dir;
}
void dfs(int x, int y, int dir) { // dir = 빛의 방향
	if (x<1 || x>n || y<1 || y>m || visited[x][y][dir]) return;
	if (x == ed.x && y == ed.y && getDir(dir, s[x][y]) == ed.dir) {
		ans++;
		return;
	}
	visited[x][y][dir] = true;
	int nDir = getDir(dir, s[x][y]);
	dfs(x + dx[nDir], y + dy[nDir], nDir);
	visited[x][y][dir] = false;
}
void recur(int idx){
	if (idx == pos.size()) {
		dfs(st.x, st.y, st.dir);
		return;
	}
	int x = pos[idx].first;
	int y = pos[idx].second;
	s[x][y] = '.';
	recur(idx + 1);
	s[x][y] = '\\';
	recur(idx + 1);
	s[x][y] = '/';
	recur(idx + 1);
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int a, b;
	cin >> n >> m >> a >> b;
	f(a, st, 0);
	f(b, ed, 2);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> s[i][j];
			if (s[i][j] == '?') {
				pos.push_back({ i,j });
			}
		}
	}
	recur(0);
	cout << ans%MOD;
	return 0;
}
