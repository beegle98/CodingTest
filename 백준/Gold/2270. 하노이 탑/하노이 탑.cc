#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int N = 100000;
const int MOD = 1000000;

int Pow[N+1];
int rod[N+1], rodCnt[3];
int n;
long long ans = 0;

vector<int> mDisk[3];

void move(int st, int ed) {
	st += 1; ed += 1;
	if (mDisk[st].empty()) return;

	int tmp = mDisk[st].back();
	mDisk[st].pop_back();
	mDisk[ed].push_back(tmp);
	cout << st << " " << ed << '\n';
}

void hanoi(int n, int st, int ed, int via) {
	if (n == 1) {
		move(st, ed);
		return;
	}
	int tmp_rod = -(via + rod[n - 1]);
	if (rod[n - 1] == via) {
		hanoi(n-1, rod[n-1], via, tmp_rod);
	}
	hanoi(n - 1, rod[n - 1], via, tmp_rod);
	//hanoi(n - 1, st, via, ed);
	move(st, ed);
	hanoi(n - 1, via, ed, st);
}

void make_pow(int n) {
	Pow[0] = 1;
	for (int i = 1; i <= n; i++) {
		Pow[i] = (2 * Pow[i - 1] % MOD);
	}
}

void go(int size, int dst_rod) {
	if (size <= 0) return;
	if (dst_rod == rod[size]) {
		go(size - 1, dst_rod);
		return;
	}
	int tmp_rod = -(dst_rod + rod[size]);
	ans += Pow[size - 1];
	ans %= 1000000;
	go(size - 1, tmp_rod);
	//hanoi(size, rod[size], dst_rod, tmp_rod);
}

int main() {
	FASTIO
	cin >> n;
	make_pow(n);
	int rodCnt[3];
	for (int i = 0; i < 3; i++) {
		cin >> rodCnt[i];
	}
	int dst;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < rodCnt[i]; j++) {
			int x; cin >> x;
			mDisk[i].push_back(x);
			rod[x] = i-1;
			if (x == n) dst = i-1;
		}
	}
	//dst = 1;
	go(n, dst);
	cout << dst + 2 << "\n";
	cout << ans;
	return 0;
}
/*
6
2 2 2
5 1
6 2
4 3
*/