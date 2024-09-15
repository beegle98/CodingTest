#include <cstdio>
long long int m;
int n, F[5][5], s[5][5];
void mul(int S[5][5]){
	int T[5][5];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			T[i][j] = 0;
			for (int l = 0; l < n; l++){
				T[i][j] += F[i][l] * S[l][j];
			}
			T[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			F[i][j] = T[i][j];
		}
	}
}
void f(long long int k){
	if (k == 1){
		return;
	}
	if (k % 2 == 0){
		f(k / 2);
		mul(F);
	}
	else{
		f(k - 1);
		mul(s);
	}
}
int main(){
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &s[i][j]);
			F[i][j] = s[i][j]%1000;
		}
	}
	f(m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%d ", F[i][j]);
		}
		printf("\n");
	}
	return 0;
}