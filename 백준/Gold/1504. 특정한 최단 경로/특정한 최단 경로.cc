#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pi;

const int INF = 1e8;

vector<pair<int,int>> Graph[801]; // [x] {y, 거리}
int Dist[3][801];
int n, m;
int v1, v2;


void dijk(int idx, int start){
	priority_queue<pi,vector<pi>,greater<pi>> pq; // 거리, 노드

	pq.push({0,start});

	Dist[idx][start]=0;

	while(!pq.empty()){
		int dist = pq.top().first; // 현재 노드까지의 거리
		int now = pq.top().second;
		pq.pop();

		
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
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,c; cin >> a >> b >>c;
		Graph[a].push_back({b,c});
		Graph[b].push_back({a,c});
	}
	cin >> v1 >> v2;

	for(int i=0;i<3;i++) fill(Dist[i],Dist[i]+n+1,INF);
	
	dijk(0,1);
	dijk(1,v1);
	dijk(2,v2);
	
	int d1 = Dist[0][v1] + Dist[1][v2] + Dist[2][n]; // 1->v1->v2->n
	int d2 = Dist[0][v2] + Dist[2][v1] + Dist[1][n]; // 1->v2->v1->n

	int ans = min(d1,d2);
	if(ans >= INF) cout << "-1";
	else cout << ans;
}