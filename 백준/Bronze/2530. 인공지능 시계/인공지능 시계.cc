#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int h, m, s; cin >> h >> m >> s;
	int sum; cin >> sum;
	sum += s + m * 60 + h * 3600;
	sum %= 24 * 3600;
	cout << sum / 3600 << " ";
	sum %= 3600;
	cout << sum / 60 << " ";
	sum %= 60;
	cout << sum;
	return 0;
}