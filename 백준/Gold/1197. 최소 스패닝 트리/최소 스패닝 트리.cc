#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef pair<int, pair<int, int>> p;

const int V = 10001;
int parent[V];
vector<p> edges;
int n,m;

int find_root(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x]);        //경로 압축
}
 
void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);
 
    if (x != y) parent[y] = x;
}
 
vector<p> kruskal() {
    vector<p> mst;
 
    for (int i = 0; i < edges.size(); i++) {
        p cur_edge = edges[i];
 
        //현재 간선이 잇는 두 정점
        int f = cur_edge.second.first;
        int s = cur_edge.second.second;
 
        //Union-Find로 사이클이 발생하는지 확인
        if (find_root(f) == find_root(s)) continue;        //사이클이 발생한다면 선택하지 않음
 
        //사이클이 발생하지 않는다면 mst에 현재 간선을 추가
        mst.push_back(cur_edge);
        //Parent 관계 갱신
        union_root(f, s);
 
        //만약 정점 개수 v에 대해 v - 1개의 간선을 찾았다면 종료
        if (mst.size() == n - 1) return mst;
    }
}
 
void init() {

	//데이터 입력
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a, b, c; cin >> a >> b >> c;
		edges.push_back({ c, {a, b} });
	}
 
    //간선들을 가중치 기준 오름차순 정렬
    sort(edges.begin(), edges.end());
 
    //Union-Find Setting
    for (int i = 1; i <= n; i++) parent[i] = i;
}
 
int main() {
    init();
    vector<p> mst = kruskal();
 
	int ans=0;
    for(int i=0;i<mst.size();i++){
		ans += mst[i].first;
	}
	cout << ans;
    return 0;
}