#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long ll;
using namespace std;

int main() {
	priority_queue<int> pq;
	int n; cin >> n;
	int n1,cnt=0; cin >> n1;
	for (int i = 1; i < n; i++) {
		int x; cin >> x;
		pq.push(x);
	}
	
	while (!pq.empty() && pq.top() >= n1) {
		int tmp = pq.top();
		pq.pop();
		tmp--;
		n1++;
		cnt++;
		pq.push(tmp);
	}
	cout << cnt;
	return 0;
}