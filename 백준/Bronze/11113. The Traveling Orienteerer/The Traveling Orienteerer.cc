#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

double len(pair<double, double> a, pair<double, double> b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<double, double>> s;
	for (int i = 0; i < n; i++) {
		double x, y; cin >> x >> y;
		s.push_back({ x,y });
	}
	int m; cin >> m;
	while (m-- > 0) {
		int t; cin >> t;
		double sum = 0;
		int prev; cin >> prev;
		for (int i = 1; i < t; i++) {
			int next; cin >> next;
			sum += len(s[prev], s[next]);
			prev = next;
		}
		printf("%.0lf\n", sum);
	}
	return 0;
}