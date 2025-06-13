#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int arr[26];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	string mobis = "MOBIS";
	for (int i = 0; i < s.size(); i++) {
		arr[s[i] - 'A'] = 1;
	}
	for (int i = 0; i < mobis.size(); i++) {
		if (!arr[mobis[i] - 'A']) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}