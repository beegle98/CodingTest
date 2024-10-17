#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;

int k, n, f, ans=-1;
int s[901][901], selected[63];

bool check(int idx, int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (s[idx][selected[i]] == 0) return false;
	}
	return true;
}

void recur(int idx, int cnt) {
	if (cnt == k) {
		ans = selected[0];
		return;
	}
	if (idx > n || ans!=-1) return;
	if (check(idx, cnt)) {
		selected[cnt] = idx;
		recur(idx + 1, cnt + 1);
	}
	recur(idx + 1, cnt);
}

int main() {
	cin >> k >> n >> f;
	for (int i = 0; i < f; i++) {
		int x, y; cin >> x >> y;
		s[x][y] = 1;
		s[y][x] = 1;
	}
	recur(1, 0);
	if (ans == -1) cout << ans;
	else {
		for (int i = 0; i < k; i++) cout << selected[i] << '\n';
	}
	return 0;
}

