#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vi s;
int n, m;

bool Check(int mid) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += min(mid, s[i]);
	}
	return m >= sum;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	cin >> n;
	s = vi(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	
	sort(s.begin(), s.end());
	cin >> m;
	int ans;
	int st = 0, ed = s[n - 1]+1;
	while (st + 1 < ed) {
		int mid = (st + ed) / 2;
		//cout << mid << '\n';
		if (Check(mid)) st = mid;
		else ed = mid;
	}
	ans = st;
	cout << ans;
	return 0;
}
