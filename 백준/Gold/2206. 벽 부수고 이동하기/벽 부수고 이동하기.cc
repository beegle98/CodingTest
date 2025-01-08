#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 1001

int di_x[4] = { -1, 1, 0, 0 };
int di_y[4] = { 0, 0, -1, 1 };
int visited[MAX][MAX];
char map[MAX][MAX];
int cnt[MAX][MAX];
int n, m;
queue<tuple<int, int, int>> q;
int oper(int x,int k){
	if (k == 0) return x - 1;
	else if (k == 1) return x + 1;
	else if (k == 2) return x * 2;
	else return x;
}
void bfs(int x,int y){
	q.push(make_tuple(x, y, true));
	visited[x][y] = true;
	cnt[x][y] = 1;
	while (!q.empty()){
		tuple<int, int, bool> v = q.front();
		q.pop();
		for (int i = 0; i < 4; i++){
			int dx = get<0>(v)+di_x[i];
			int dy = get<1>(v)+di_y[i];
			bool wall = get<2>(v);
			if (dx < 0 || dx >= n || dy < 0 || dy >= m || visited[dx][dy] == 1) continue;
			if (map[dx][dy] == '1'){
				if (wall) wall = false;
				else continue;
			}
			if (wall) visited[dx][dy] = 1;
			else{
				if (visited[dx][dy] == 2) continue;
				else visited[dx][dy] = 2;
			}
			cnt[dx][dy] = cnt[get<0>(v)][get<1>(v)] + 1;
			if (dx == n - 1 && dy == m - 1) return;
			q.push(make_tuple(dx, dy, wall));
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; i++){
		scanf("%s", map[i]);
	}
	bfs(0,0);
	if (visited[n - 1][m - 1]) printf("%d", cnt[n-1][m-1]);
	else printf("-1");
	return 0;
}