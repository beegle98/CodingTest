#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n;
bool visited[100][100];
string str[100];

void dfs(int x,int y){
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n 
            || str[nx][ny] != str[x][y] || visited[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> str[i];
    int ans1, ans2, cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
            if (str[i][j] == 'R') str[i][j] = 'G';
        }
    }
    ans1 = cnt;
    cnt = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    ans2 = cnt;
    cout << ans1 << ' ' << ans2;
    return 0;
}