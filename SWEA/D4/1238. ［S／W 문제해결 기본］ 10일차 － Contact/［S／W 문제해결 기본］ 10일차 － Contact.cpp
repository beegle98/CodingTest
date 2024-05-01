#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

const int N = 100;
queue<pi> q;
vi s[N+1];
bool visited[N+1];
int Max,len;

void bfs(pi x){
    if(visited[x.first]) return;
    visited[x.first]=1;

    if(q.front().second>len){
                len = q.front().second;
                Max = q.front().first;
            }
    else if(Max<q.front().first) Max = q.front().first;

    for(int i=0;i<s[x.first].size();i++){
        q.push({s[x.first][i],x.second+1});
    }
}

int main(){
 
    int ans,T=10;
    for(int t=1;t<=T;t++){
        
        for(int i=0;i<N+1;i++) s[i].clear();
        memset(visited,0,sizeof(bool)*N+1);
        int n,st; cin >> n >> st;
        for(int i=0;i<n/2;i++){
            int x,y; cin >> x >> y;
            s[x].push_back(y);
        }
        visited[st]=1;
        for(int i=0;i<s[st].size();i++){
            q.push({s[st][i],1});
        }
        Max=st,len=0;
        while(!q.empty()){
            bfs(q.front());
            q.pop();
        }
        ans = Max;

        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}