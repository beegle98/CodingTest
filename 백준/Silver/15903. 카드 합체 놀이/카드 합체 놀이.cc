#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long ll;
using namespace std;

int main() {
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		pq.push(x);
	}
	for (int i = 0; i < m; i++) {
		ll tmp;
		tmp = pq.top();
		pq.pop();
		tmp += pq.top();
		pq.pop();
		pq.push(tmp);
		pq.push(tmp);
	}
	ll sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
	return 0;
}