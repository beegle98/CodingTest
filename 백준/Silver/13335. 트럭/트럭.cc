#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, w, L; cin >> n >> w >> L;
	vi s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	queue<pi> q;
	int ans = 0, t = 0, sum = s[0];
	q.push({ s[t++], ans++ });
	while (t < n) {
		int x = q.front().first;
		int y = q.front().second;
		if (ans - y >= w) {
			q.pop();
			sum -= x;
		}
		if (sum + s[t] <= L) {
			q.push({s[t],ans});
			sum += s[t++];
		}
		ans++;
	}
	cout << ans + w;
	return 0;
}