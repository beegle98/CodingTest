#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

typedef long long int ll;

using namespace std;

int dp[100001];

int main(void)
{
	int w[101], v[101];
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &w[i], &v[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = k; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	printf("%d\n", dp[k]);
	return 0;
}
