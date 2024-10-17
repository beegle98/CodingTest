#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
	int n, cnt=0; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x & 1) cnt++;
	}
	cout << cnt;
	return 0;
}

