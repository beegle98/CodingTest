#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

string s[10001];
int n,m,ans = 0;
bool visited[10001][501];

bool dfs(int x,int y){
    if (x<0 || x>=n || y>=m || visited[x][y] || s[x][y]=='x') return 0;
    visited[x][y] = true;
    if (y == m - 1) {
        ans++;
        return 1;
    }
    if (dfs(x - 1, y + 1)) return 1;
    if (dfs(x, y + 1)) return 1;
    if (dfs(x+1, y + 1)) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        dfs(i, 0);
    }
    cout << ans;
    return 0;
}