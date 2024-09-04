#include <stdio.h>	
int MIN(int x, int y){
	return x < y ? x : y;
}
int main(){
	int n, s[3] = { 0, 0, 0 }, t[3], min;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d %d", &t[0], &t[1], &t[2]);
		t[0] += MIN(s[1], s[2]);
		t[1] += MIN(s[0], s[2]);
		t[2] += MIN(s[0], s[1]);
		for (int j = 0; j < 3; j++){
			s[j] = t[j];
		}
	}
	min = s[0];
	for (int i = 1; i < 3; i++){
		if (s[i] < min){
			min = s[i];
		}
	}
	printf("%d", min);
	return 0;
}