#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vi s[100001];
vi ans(100001);

void dfs(int x) {
	//cout << x << '\n';
	for(int i=0;i<s[x].size();i++){
		if (ans[s[x][i]] != 0) continue;
		ans[s[x][i]] = x;
		dfs(s[x][i]);

	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	for (int i = 0; i < n-1; i++) {
		int x, y; cin >> x >> y;
		s[x].push_back(y);
		s[y].push_back(x);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
