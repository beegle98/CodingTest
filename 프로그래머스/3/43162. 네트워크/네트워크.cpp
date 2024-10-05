#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
vector<vector<int>> v(200);
bool visited[200];

void dfs(int n){
    for(int i=0;i<N;i++){
        if(visited[i] || v[n][i]==0) continue;
        visited[i]=true;
        dfs(i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int ans = 0;
    N = n;
    for(int i=0;i<n;i++){
        v[i]=computers[i];
    }
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        ans++;
        visited[i]=true;
        dfs(i);
    }
    return ans;
}