#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct Pos {
	int x, h, flag;
};

int n;

int main() {
	FASTIO
	cin >> n;
	vector<Pos> building;
	for (int i = 0; i < n; i++) {
		int l, h, r; cin >> l >> h >> r;
		building.push_back({ l,h,0 });
		building.push_back({ r,h,1 });
	}
	sort(building.begin(), building.end(), [&](Pos a, Pos b) {
		if (a.x != b.x) return a.x < b.x;
		if (a.flag != b.flag) return a.flag < b.flag;
		return !a.flag ? a.h > b.h : a.h < b.h;
	});

	multiset<int> Set;
	for (Pos p : building) {
		if (!p.flag) {
			if (Set.empty() || *Set.rbegin() < p.h) cout << p.x << ' ' << p.h << ' ';
			Set.insert(p.h);
		}
		else {
			auto it = Set.find(p.h);
			if (it != Set.end()) Set.erase(it);
			if (Set.empty()) cout << p.x << ' ' << 0 << ' ';
			else if (p.h > *Set.rbegin()) cout << p.x << ' ' << *Set.rbegin() << ' ';
		}
	}
	return 0;
}
