#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int INF = 1e9;

struct Pos{
	int x;
	int y;
	int cost;

	bool operator < (const Pos& t) const{
		return cost > t.cost;
	}
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int MAP[130][130];
int Cost[130][130];
int n;

void dijk(Pos start){
	
	priority_queue<Pos> pq;
	pq.push(start);

	while(!pq.empty()){

		Pos now = pq.top();
		pq.pop();

		if(now.x==n-1 && now.y==n-1) break;
		if(Cost[now.x][now.y] < now.cost) continue;

		for(int i=0;i<4;i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >=n) continue;
			int nCost = now.cost + MAP[nx][ny];
			if(Cost[nx][ny] > nCost){
				Cost[nx][ny] = nCost;
				pq.push({nx,ny,nCost});
			}

		}
	}
}

int main() {
	FASTIO
	int tc=0;
	while(1){
		tc++;
		cin >> n;
		if(n==0) break;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> MAP[i][j];
				Cost[i][j]=INF;
			}
		}
		dijk({0,0,MAP[0][0]});
		cout << "Problem " << tc << ": " << Cost[n-1][n-1] << '\n';
	}
	
	return 0;
}
