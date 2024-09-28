#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int N = 1000001;
deque<int> dq;

int main() {
	FASTIO
	int n; cin >> n;
	int x; cin >> x;
	ll ans = 0;
	dq.push_back(x);
	for (int i = 1; i < n; i++) {
		cin >> x;
		if (dq.back() > x) dq.push_back(x);
		else {
			ans += x - dq.back();
			while (!dq.empty() && dq.back() <= x) {
				dq.pop_back();
			}
			dq.push_back(x);
		}
	}
	if (dq.size() > 1) {
		ans += dq.front() - dq.back();
	}
	cout << ans;
	return 0;
}