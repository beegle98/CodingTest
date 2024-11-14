#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

vi ans;
int back[1000001];

void solve(int n) {
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == 1) {
			while (back[x] != 0) {
				ans.push_back(x);
				x = back[x];
			}
			ans.push_back(x);
			return;
		}
		if (x % 3 == 0 && back[x / 3] == 0) {
			back[x / 3] = x;
			q.push(x / 3);
		}
		if (x % 2 == 0 && back[x / 2] == 0) {
			back[x / 2] = x;
			q.push(x / 2);
		}
		if (back[x - 1] == 0) {
			back[x - 1] = x;
			q.push(x - 1);
		}
	}
}

int main() {
	int n; cin >> n;
	solve(n);
	cout << ans.size() - 1 << '\n';
	for (int i = ans.size()-1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}
	return 0;
}

