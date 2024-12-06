#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, ans; cin >> a >> b;
	if (a < b) ans = -1;
	else if (a > b) ans = 1;
	else ans = 0;
	cout << ans;
	return 0;
}