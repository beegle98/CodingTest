#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, m, arr[100][100], ans;//치킨 거리의 최솟값
vector<pair<int, int>> chicken,home;
bool open[15];

int minDis(int x, int y) {
	int MIN = 100000;
	for (int i = 0; i < chicken.size(); i++) {
		int cx = chicken[i].first;
		int cy = chicken[i].second;
		if (open[i]) {
			MIN = min(MIN, abs(x - cx) + abs(y - cy));
		}
	}
	return MIN;
}

void recur(int index, int cnt) {
	//cout << index << " : " << cnt << '\n';
	if (cnt == m) {
		int sum = 0;
		for (int i = 0; i < home.size(); i++) {
			sum += minDis(home[i].first, home[i].second);
		}
		ans = min(ans, sum);
	}
	if (index >= chicken.size()) return;
	open[index] = true;
	recur(index + 1, cnt + 1);
	open[index] = false;
	recur(index + 1, cnt);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				home.push_back({ i,j });
			}
			else if (arr[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	ans = 100000000;
	recur(0, 0);
	cout << ans;
}