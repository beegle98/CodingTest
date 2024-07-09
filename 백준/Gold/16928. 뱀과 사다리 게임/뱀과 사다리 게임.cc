#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

map<int,int> a;
bool visited[200];
queue<pi> q;
int ans=0;

void bfs(pi p){
    int x = p.first;
    if(x>100 || visited[x]) return;
    //cout << x << '\n';
    visited[x]=1;
    if(x==100){
        ans=p.second;
        while(!q.empty()) q.pop();
    }
    else{
        
        for(int i=1;i<=6;i++){
            if(a.find(x+i)!=a.end()){
                q.push({a[x+i],p.second+1});
            }
            else q.push({x+i,p.second+1});
        }
    }
    
}
int main()
{
    FASTIO
    int n,m; cin >> n >> m;
    for(int i=0;i<n+m;i++){
        int x,y; cin >> x >> y;
        a[x]=y;
    }
    q.push({1,0});
    while(!q.empty()){
        pi tmp = q.front();
        q.pop();
        bfs(tmp);
    }
    cout << ans << '\n';
    return 0;
}