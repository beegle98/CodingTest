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
	for(int i=0;i<n;i++){
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (j == 0 || s[j] != s[j - 1]) cout << s[j];
		}
		cout << '\n';
	}
	
	return 0;
}