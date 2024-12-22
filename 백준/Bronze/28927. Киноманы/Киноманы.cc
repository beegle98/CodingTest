#include <bits/stdc++.h>

using namespace std;

int main() {
	int t1, e1, f1; cin >> t1 >> e1 >> f1;
	int t2, e2, f2; cin >> t2 >> e2 >> f2;
	int sum1 = 0, sum2 = 0;
	sum1 = t1 * 3 + e1 * 20 + f1 * 120;
	sum2 = t2 * 3 + e2 * 20 + f2 * 120;
	if (sum1 > sum2) cout << "Max";
	else if (sum1 == sum2) cout << "Draw";
	else cout << "Mel";
	return 0;
}