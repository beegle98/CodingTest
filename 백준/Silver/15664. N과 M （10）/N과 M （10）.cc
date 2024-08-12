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
bool dup[10];
bool visited[10][10001];

void dfs(int index, int cnt, int end) {
	if (cnt >= end) {
		for (int i = 0; i < end; i++) {
			cout << save[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = index; i < n; i++) {
		if (visited[cnt][arr[i]] || dup[i]) continue;
		visited[cnt][arr[i]] = 1;
		dup[i] = 1;
		save[cnt] = arr[i];
		dfs(i+1, cnt + 1, end);
		dup[i] = 0;
		
	}
	for(int i=0;i<n;i++) visited[cnt][arr[i]] = 0;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	dfs(0, 0, m);
	return 0;
}