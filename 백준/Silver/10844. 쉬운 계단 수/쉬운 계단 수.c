#include <stdio.h>
int main(){
	int n, dp[10][101],sum=0;
	dp[0][1] = 0;
	scanf("%d", &n);
	for (int i = 1; i < 10; i++){
		dp[i][1] = 1;
	}
	for (int i = 2; i <= n; i++){
		dp[0][i] = dp[1][i-1];
		dp[9][i] = dp[8][i-1];
		for (int j = 1; j <= 8; j++){
			dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1])%1000000000;
		}
	}
	for (int i = 0; i < 10; i++){
		sum = (sum + dp[i][n]) % 1000000000;
	}
	printf("%d", sum);
	return 0;
}