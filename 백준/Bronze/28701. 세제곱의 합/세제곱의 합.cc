#include <bits/stdc++.h>

using namespace std;


int main() {
	int n, sum1 = 0, sum2 = 0; cin >> n;
	for (int i = 1; i <= n; i++) {
		sum1 += i;
		sum2 += i * i * i;
	}
	cout << sum1 << '\n' << sum1*sum1 << '\n' << sum2;
	return 0;
}