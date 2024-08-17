#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pi;

struct Vertex{
	int cost; // 비용
	int idx; // 마지막 노드 인덱스
	vector<int> course; // 코스

	bool operator < (const Vertex& t) const{
		return cost > t.cost;
	}
};

const int INF = 1e9+7;

const int N = 1000;

vector<pair<int,int>> Graph[N+1]; // [x] {y, 거리}
Vertex Cost[N+1];
int n, m;



void dijk(int start){
	priority_queue<Vertex> pq;

	vector<int> st;
	st.push_back(start);
	pq.push({0,start,st});

	Cost[start].cost=0;
	Cost[start].course=st;

	while(!pq.empty()){
		int dist = pq.top().cost; // 현재 노드까지의 비용
		int now = pq.top().idx;
		vector<int> cour = pq.top().course;
		pq.pop();
		
		if(Cost[now].cost < dist) continue;

		for(int i=0;i<Graph[now].size();i++){
			int w = Graph[now][i].first;
			int wCost = dist + Graph[now][i].second;// 다음 노드까지의 거리

			if(wCost < Cost[w].cost){
				//cout << now  <<", " << w << " : " << wCost << ' ' << Cost[w].cost << '\n';
				vector<int> tmp = cour;
				tmp.push_back(w);
				Cost[w].cost = wCost;
				Cost[w].course = tmp;
				pq.push({wCost,w,tmp});
			}
		}

	}
}

int main() {
	FASTIO
	int st,en;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,c; cin >> a >> b >>c;
		Graph[a].push_back({b,c});
	}
	cin >> st >> en;
	for(int i=1;i<=n;i++){
		Cost[i].cost=INF;
	}
	
	dijk(st);
	cout << Cost[en].cost << '\n';
	cout << Cost[en].course.size() << '\n';
	for(int i=0;i<Cost[en].course.size();i++){
		cout << Cost[en].course[i] << ' ';
	}
}