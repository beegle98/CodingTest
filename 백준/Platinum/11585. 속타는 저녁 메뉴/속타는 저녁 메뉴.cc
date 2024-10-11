#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<char> vc;

vi getPi(vc p) {
	int m = p.size(), j = 0;
	vi pi(m);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
int kmp(vc s, vc p) {
	int sum = 0;
	vi pi = getPi(p);
	int n = s.size()-1, m = p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				sum++;
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return sum;
}
int main() {
	int n; cin >> n;
	vector<char> s(n * 2), p(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		s[n + i] = s[i];
	}
	for (int i = 0; i < n; i++) cin >> p[i];
	int ans = kmp(s, p);
	for (int i = 2; i <= ans; i++) {
		if (ans%i == 0 && n%i == 0) {
			ans /= i;
			n /= i;
			i--;
		}
	}
	cout << ans << "/" << n;
	return 0;
}

