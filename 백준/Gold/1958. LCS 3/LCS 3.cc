#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);


const int N = 101;
string s1, s2, s3;
int lcs[N][N][N];

int main() {
	FASTIO
	cin >> s1 >> s2 >> s3;
	int n, m, l; 
	n = s1.size();
	m = s2.size();
	l = s3.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < l; k++) {
				if (s1[i] == s2[j] && s2[j]==s3[k]) {
					lcs[i + 1][j + 1][k+1] = lcs[i][j][k] + 1;
				}
				else {
					lcs[i + 1][j + 1][k + 1] = max({ lcs[i + 1][j][k], lcs[i][j + 1][k], lcs[i][j][k + 1],
						lcs[i+1][j+1][k], lcs[i+1][j][k+1], lcs[i][j+1][k+1] });
				}
			}
		}
	}
	cout << lcs[n][m][l] << '\n';
	return 0;
}
