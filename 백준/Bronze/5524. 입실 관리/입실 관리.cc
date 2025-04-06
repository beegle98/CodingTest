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
	while (n-- > 0) {
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if ('A' <= s[i] && s[i] <= 'Z') {
				cout << char(s[i] + 'a' - 'A');
			}
			else cout << s[i];
		}
		cout << '\n';
	}
	
	return 0;
}