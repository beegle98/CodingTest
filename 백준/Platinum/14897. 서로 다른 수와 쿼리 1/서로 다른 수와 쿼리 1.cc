#include <bits/stdc++.h>
using namespace std;

int sqrtN = 2000;

struct Query{
	int idx, s, e;

	bool operator < (Query &x){
		if(s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
		return e < x.e;
	}
};

vector<int> v, tmp;
vector<Query> query;
int n, q;
int mp[1010101];
vector<int> ans;
int now = 0;

void sub(int i){
	mp[v[i]]--;
	if(mp[v[i]] == 0) now--;
}

void add(int i){
	if(mp[v[i]] == 0) now++;
	mp[v[i]]++;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n; v.resize(n+1);
	for(int i=1; i<=n; i++) cin >> v[i];
	tmp = v;
	sort(tmp.begin()+1, tmp.end());
	tmp.erase(unique(tmp.begin()+1, tmp.end()), tmp.end());
	for(int i=1; i<=n; i++){
		v[i] = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
	}

	cin >> q; query.resize(q); ans.resize(q);
	for(int i=0; i<q; i++){
		cin >> query[i].s >> query[i].e;
		query[i].idx = i;
	}
	sort(query.begin(), query.end());

	int s = 0;
	int e = 0;

	for(int i=0; i<q; i++){
		int idx = query[i].idx;
		while(s < query[i].s) sub(s++);
		while(s > query[i].s) add(--s);
		while(e < query[i].e) add(++e);
		while(e > query[i].e) sub(e--);
		ans[idx] = now;
	}

	for(auto i : ans) cout << i << "\n";
}