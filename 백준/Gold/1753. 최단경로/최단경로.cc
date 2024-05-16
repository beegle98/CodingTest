#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;


const int INF = 1000000000;
int n,m,ans[20001];
vector<pi> s[20001];
priority_queue<pi,vector<pi>,greater<pi>> pq;

void dijk(pi v){
    int x=v.second,w=v.first;
    if(ans[x]!=INF)  return;
    ans[x]=w;
    for(int i=0;i<s[x].size();i++){
        pq.push({w+s[x][i].first,s[x][i].second});
    }
    
}

int main(){
    FASTIO
    cin >> n >> m;
    int k; cin >> k;
    for(int i=1;i<=n;i++) ans[i]=INF;
    for(int i=0;i<m;i++){
        int x,y,w; cin >> x >> y >> w;
        s[x].push_back({w,y});
    }
    pq.push({0,k});
    while(!pq.empty()){
        pi tmp = pq.top();
        pq.pop();
        dijk(tmp);
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==INF) cout << "INF\n";
        else cout << ans[i] << '\n';
    }
    return 0;
}