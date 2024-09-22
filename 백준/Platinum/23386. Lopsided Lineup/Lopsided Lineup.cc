#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;

int main() {
	FASTIO
	
	int n; cin >> n;
	vector<ll> v;
	long ans=0;
	for(int i=0;i<n;i++){
		long sum=0;
		for(int j=0;j<n;j++){
			int x; cin >> x;
			sum+=x;
		}
		v.push_back(sum);
		ans+=sum;
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n/2;i++) ans-=v[i]*2;
	cout << ans/2;
	return 0;
}