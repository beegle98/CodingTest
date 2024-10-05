#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int x,y;
    int cost;
    bool operator < (const Edge& e) const{
        return cost < e.cost;
    }
};

int parent[101];
vector<Edge> edges;

int find_root(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x]);
}
 
bool union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if(x==y) return false;
    parent[y] = x;
    return true;
}

int kruskal(int n) {
    int cnt=0, res=0;
    for (int i = 0; i < edges.size(); i++) {
        if(union_root(edges[i].x, edges[i].y)){
            cnt++;
            res+=edges[i].cost;
        }
        if (cnt == n - 1) break;
    }
    return res;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0;i<costs.size();i++){
        int x = costs[i][0];
        int y = costs[i][1];
        int c = costs[i][2];
        edges.push_back({x,y,c});
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<n;i++) parent[i]=i;
    answer = kruskal(n);
    return answer;
}