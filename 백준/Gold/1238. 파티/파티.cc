#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pi;

const int INF = 1e9;

const int N = 1000;

vector<pair<int,int>> Graph[N+1]; // [x] {y, 거리}
int Dist[N+1][N+1];
int n, m, dst;
int v1, v2;


void dijk(int flag, int idx, int start){
	priority_queue<pi,vector<pi>,greater<pi>> pq; // 거리, 노드

	pq.push({0,start});

	Dist[idx][start]=0;

	while(!pq.empty()){
		int dist = pq.top().first; // 현재 노드까지의 거리
		int now = pq.top().second;
		pq.pop();

		if(flag && now == dst) break;
		if(Dist[idx][now] < dist) continue;

		for(int i=0;i<Graph[now].size();i++){
			int w = Graph[now][i].first;
			int wDist = dist + Graph[now][i].second;// 다음 노드까지의 거리

			if(wDist < Dist[idx][w]){
				Dist[idx][w] = wDist;
				pq.push({wDist,w});
			}
		}

	}
}

int main() {
	FASTIO
	cin >> n >> m >> dst;
	for(int i=0;i<m;i++){
		int a,b,c; cin >> a >> b >>c;
		Graph[a].push_back({b,c});
	}

	for(int i=1;i<=n;i++) fill(Dist[i],Dist[i]+n+1,INF);
	
	dijk(0,dst,dst);
	for(int i=1;i<=n;i++){
		dijk(1,i,i);
	}
	
	int ans = 0;
	for(int i=1;i<=n;i++){
		int d = Dist[i][dst] + Dist[dst][i];
		ans = max(ans,d);
		//cout << Dist[i][dst] << ' ' << Dist[dst][i] << '\n';
	}
	cout << ans;
}