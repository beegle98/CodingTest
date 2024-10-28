#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;


int main() {
	int n; cin >> n;
	if (!n) {
		cout << "0";
		return 0;
	}
	priority_queue<pi> pq;
	vector<pi> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	int sum=0, Max = v.back().first;

	for (int t = Max; t >=1; t--) {
		while (!v.empty() && t <= v.back().first) {
			pi p = v.back();
			v.pop_back();
			pq.push({p.second, p.first});
		}
		if (!pq.empty()) {
			pi tmp = pq.top();
			pq.pop();
			sum += tmp.first;
		}
	}
	cout << sum;
	return 0;
}

