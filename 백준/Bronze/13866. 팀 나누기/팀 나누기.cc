#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int stat[4];
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> stat[i];
		sum += stat[i];
	}
	int ans = 100000000;
	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 4; j++) {
			ans = min(ans,abs(sum - (stat[i] + stat[j]) * 2));
		}
	}
	cout << ans;
	return 0;
}