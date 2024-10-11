#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


vi getPi(vi p) {
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
bool kmp(vi s, vi p) {
	
	vi pi = getPi(p);
	int n = s.size(), m = p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				return true;
			}
			else {
				j++;
			}
		}
	}
	return false;
}
int main() {
	int n, k; cin >> n >> k;
	int m; cin >> m;
	vi p(m);
	for (int i = 0; i < m; i++) cin >> p[i];
	vector<vi> v;
	
	for (int i = 0; i <= p.size()-k; i++) {
		vi tmp(k);
		tmp.assign(p.begin() + i, p.begin() + i + k);
		v.push_back(tmp);
	}
	for (int i = 1; i < n; i++) {
		cin >> m;
		vi s(m*2+1);
		s[m] = 0;
		for (int j = 0; j < m; j++) {
			cin >> s[j];
			s[2 * m - j] = s[j];
			
		}
		//for (int j = 0; j < s.size(); j++) cout << s[j] << " ";
		//cout << "\n";
		for (int j = 0; j < v.size(); j++) {
			if (!kmp(s, v[j])) {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	
	if (!v.empty()) cout << "YES";
	else cout << "NO";

	return 0;
}

