#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, k, MAX = 0, arr[100];

void f(int x, int cnt, int check) {
	if (x >= 26) return;
	if (cnt <= 0) {
		int sum = 0;
		for (int i = 0; i < n; i++) {	
			if ((arr[i] & check) == arr[i]) sum++;
		}
		MAX = max(MAX, sum);
		return;
	}
	f(x + 1, cnt, check);
	if ((check & (1 << (x + 1))) == 0) f(x + 1, cnt - 1, check | (1 << (x + 1)));
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		arr[i] = 0;
		for (int j = 0; j < s.size(); j++) {
			arr[i] |= 1 << (s[j] - 'a');
		}
	}
	int check = 0;
	check |= 1 << ('a' - 'a');
	check |= 1 << ('n' - 'a');
	check |= 1 << ('t' - 'a');
	check |= 1 << ('c' - 'a');
	check |= 1 << ('i' - 'a');
	
	if(k>=5) f(0, k - 5,check);
	cout << MAX;
	return 0;
}
