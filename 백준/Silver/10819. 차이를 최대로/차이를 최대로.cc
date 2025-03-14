#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vi s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s.begin(), s.end());
	int ans=0;
	do{
		int sum = 0;
		for (int i = 1; i < n; i++) {
			sum += abs(s[i] - s[i - 1]);
		}
		ans = max(ans, sum);
	} while (next_permutation(s.begin(), s.end()));
	cout << ans;
	return 0;
}