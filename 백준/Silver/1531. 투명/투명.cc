#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int s[101][101];

void f(int x1, int y1, int x2, int y2) {
	for (int i = x1;i <= x2;i++) {
		for (int j = y1;j <= y2;j++) {
			s[i][j]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0;i < n;i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		f(x1, y1, x2, y2);
	}
	int ans = 0;
	for (int i = 1;i <= 100;i++) {
		for (int j = 1;j <= 100;j++) {
			if (s[i][j] > m) ans++;
		}
	}
	cout << ans;
	return 0;
}