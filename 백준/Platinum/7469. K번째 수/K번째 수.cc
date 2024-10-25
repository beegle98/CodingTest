#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;

int n, m;
vector<pair<int, int>> v;// {value, index}

int solve(int l, int r, int k) {
	int res = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second >= l && v[i].second <= r) cnt++;
		if (cnt == k) {
			res = v[i].first;
			break;
		}
	}
	return res;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		v.push_back({ x,i });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		int l, r, k; cin >> l >> r >> k;
		cout << solve(l, r, k) << '\n';
	}
	return 0;
}

