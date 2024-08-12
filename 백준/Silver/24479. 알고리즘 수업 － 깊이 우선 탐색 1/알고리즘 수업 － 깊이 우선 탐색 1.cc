#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

vi s[100001];
int cnt=1, ans[100001];

void dfs(int v){
    if(ans[v]) return;
    ans[v]=cnt++;
    for(int i=0;i<s[v].size();i++){
        dfs(s[v][i]);
    }
}

int main()
{
    FASTIO
    int n,m,r; cin >> n >> m >> r;
    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        s[x].push_back(y);
        s[y].push_back(x);
    }
    for(int i=0;i<n;i++) sort(s[i].begin(),s[i].end());
    dfs(r);
    for(int i=1;i<=n;i++){
        cout << ans[i] << '\n';
    }
    return 0;
}