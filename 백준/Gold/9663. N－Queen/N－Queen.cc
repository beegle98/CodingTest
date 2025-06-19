#include <iostream>
#include <cmath>
#include <time.h>
#define MAX_SIZE 15
using namespace std;
int board[MAX_SIZE];
int n, cnt=0;
void path(int y) {
	int ko;
	if (y == n) {
		cnt++;
		return;
	}
	for (int i = 0; i<n; i++) {
		ko = 1;
		for (int j = 0; j<y; j++) {
			if (board[j] == i || abs(y - j) == abs(i - board[j])) {
				ko = 0;
				break;
			}
		}
		if (ko) {
			board[y] = i;
			path(y + 1);
		}
	}
}
int main() {
	cin >> n;
	path(0);
	cout << cnt << endl;
	return 0;
}