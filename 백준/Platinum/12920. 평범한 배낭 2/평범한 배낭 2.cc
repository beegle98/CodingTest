#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define X first
#define Y second
typedef pair<int,int> pi;
struct bp{
	int v,c,k;
};

int main() {
	FASTIO
	
	int n, m; cin >> n >> m;
	vector<bp> s(n);
	vector<pi> dp(m+1);
	for (int i = 0; i < n; i++) cin >> s[i].v >> s[i].c >> s[i].k;

	sort(s.begin(),s.end(),[](bp a,bp b)->bool {return (double)a.c/a.v > (double)b.c/b.v;});

	for (int i = 0; i < n; i++) {

		vector<pi> tmp = dp;
		for(int i=0;i<=m;i++) tmp[i].Y=0;

		for (int j = s[i].v; j<= m; j++) {
			
			if(dp[j].X < tmp[j-s[i].v].X + s[i].c){
				if(tmp[j-s[i].v].Y<s[i].k ){
					tmp[j].X = tmp[j-s[i].v].X + s[i].c;
					tmp[j].Y = tmp[j-s[i].v].Y+1;
				}else{
					tmp[j].X = dp[j-s[i].v*s[i].k].X + s[i].c*s[i].k;
					tmp[j].Y = s[i].k;
				}
			}
		}
		dp=tmp;
	}
	cout << dp[m].X;
	return 0;
}