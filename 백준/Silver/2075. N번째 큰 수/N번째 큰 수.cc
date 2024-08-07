#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie();
	int x,n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pq.push(x);
	}
	for (int i = 0; i < n*(n-1); i++) {
		cin >> x;
		pq.push(x);
		pq.pop();
	}
	cout << pq.top() << '\n';
	return 0;
}