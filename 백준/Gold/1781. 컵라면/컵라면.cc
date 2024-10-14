#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> pi;

priority_queue<pi,vector<pi>,less<pi>> pq;
int main() {
	int n; cin >> n;
	int ans = 0;
	vector<pi> v;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (int i = n; i >= 1; i--) {
		while (!v.empty() && v.back().first >= i) {
			pq.push({ v.back().second,v.back().first });
			v.pop_back();
		}
		if (!pq.empty()) {
			pi top = pq.top();
			//cout << top.first << " " << top.second << '\n';
			ans += top.first;
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}

