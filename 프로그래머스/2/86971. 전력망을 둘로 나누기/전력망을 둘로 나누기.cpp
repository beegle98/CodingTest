#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

vector<int> list[101];
bool visited[101];

int dfs(int x,int cnt){
    for(int i : list[x]){
        if(visited[i]) continue;
        visited[i] = true;
        cnt = dfs(i,cnt+1);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int ans = 100;
    for(int i=0;i<wires.size();i++){
        int a = wires[i][0]; int b = wires[i][1];
        list[a].push_back(b); list[b].push_back(a);
    }
    for(int i=0;i<wires.size();i++){
        int a = wires[i][0]; int b = wires[i][1];
        memset(visited,false,sizeof(visited));
        visited[a]=true; visited[b]=true;
        int res1 = dfs(a,1);
        int res2 = dfs(b,1);
        ans = min(ans,abs(res1-res2));
    }
    return ans;
}