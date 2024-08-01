#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <limits>

using namespace std;

int n, m;
vector<int> arr;
int save[10];
bool visited[10];

void dfs(int index, int end) {
	if (index >= end) {
		for (int i = 0; i < end; i++) {
			cout << save[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		save[index] = arr[i];
		dfs(index + 1, end);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	dfs(0, m);
	return 0;
}