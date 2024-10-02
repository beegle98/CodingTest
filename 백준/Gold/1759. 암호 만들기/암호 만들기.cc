#include<iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;

using namespace std;
int L, C;
char arr[20], list[20];


bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}

void comb(int cnt, int idx, int v) {
	if (cnt == L) {
		if (v >= 1 && L - v >= 2) {
			for (int i = 0; i < L; i++) cout << list[i];
			cout << '\n';
		}
		return;
	}
	for (int i = idx; i < C; i++) {
		list[cnt] = arr[i];
		comb(cnt + 1, i + 1, isVowel(arr[i])?v+1:v);
	}
}
int main(void)
{
	FASTIO
	 cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> arr[i];
	sort(arr, arr + C);
	comb(0,0,0);
	return 0;
}
