#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int s[1010][1010];
#define MAX(a,b) a > b ? a : b
int main(){
	char a[1001], b[1001];
	scanf("%s", a);
	scanf("%s", b);
	for (int i = 1; i <= strlen(a); i++){
		for (int j = 1; j <= strlen(b); j++){
			if (a[i - 1] == b[j - 1]){
				s[i][j] = s[i - 1][j - 1] + 1;
			}
			else{
				s[i][j] = MAX(s[i - 1][j], s[i][j - 1]);
			}
		}
	}
	printf("%d", s[strlen(a)][strlen(b)]);
	return 0;
}