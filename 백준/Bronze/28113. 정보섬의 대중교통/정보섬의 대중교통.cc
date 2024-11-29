#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a, b, ans; cin >> n >> a >> b;
	string s[3] = { "Bus", "Subway", "Anything" };
	if (a < b || a < n) ans = 0;
	else if (a == b && b >= n) ans = 2;
	else ans = 1;
	cout << s[ans];
	return 0;
}