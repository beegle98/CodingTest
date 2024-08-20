#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int N = 200000;
unordered_map<int, long long> Hash;
int sum[N + 1];
int n, k;

int main() {
	FASTIO
	long long ans = 0;
	cin >> n >> k;
	Hash[0] = 1;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		sum[i] = sum[i - 1] + a;

		ans += Hash[sum[i] - k];

		Hash[sum[i]]++;
	}
	cout << ans;
	return 0;
}
