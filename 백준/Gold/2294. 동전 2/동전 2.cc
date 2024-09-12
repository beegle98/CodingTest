#include <stdio.h>
int n, k, sum[10001],s[101];
int main(){
	int i, j, tmp;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++){
		scanf("%d", &s[i]);
	}
	for (i = 0; i < n; i++){
		for (j = i + 1; j < n; j++){
			if (s[i] > s[j]){
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++){
		for (j = 1; j <= k; j++){
			if (j == s[i]) sum[j] = 1;
			else if (j > s[i]&&sum[j-s[i]]!=0){
				if (sum[j] == 0 || sum[j]>sum[j - s[i]] + 1) sum[j] = sum[j - s[i]] + 1;
			}
		}
	}
	if (sum[k] == 0) printf("-1");
	else printf("%d", sum[k]);
	return 0;
}