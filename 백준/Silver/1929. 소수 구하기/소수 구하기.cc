#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int s[1000001] = {0,};
int main() {
	int n, m,i,p;
	scanf("%d%d", &n, &m);
	s[1] = 1;
	p = 2;
	while (p*p<=m) {
		if (s[p] == 0) {
			for (i = p * 2; i <= m; i += p) s[i] = 1;
		}
		p++;
	}
	for (i = n; i <= m; i++) {
		if (s[i] == 0) printf("%d\n", i);
	}
}