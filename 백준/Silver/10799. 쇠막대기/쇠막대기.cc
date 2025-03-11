#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s; cin >> s;
	int n = s.size();
	int ans = 0, stick=0;
	for (int i = 0;i < n;i++) {
		if (s[i] == '(') stick++;
		else {
			if (s[i - 1] == '(') {
				stick--;
				ans += stick;
			}
			else {
				stick--;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}