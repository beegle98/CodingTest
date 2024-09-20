#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
const int N = 100001;


int main() {
	FASTIO
	int n,m; cin >> n >> m;
	ll arr[N], sum=0, frontSum=0, ans=0;
	for(int i=0;i<m;i++){
		cin >> arr[i];
		sum+=arr[i];
	}
	ans = max(ans,sum);
	for(int i=m;i<n;i++){
		cin >> arr[i];
		frontSum+=arr[i-m];
		if(frontSum<0) frontSum = 0;
		sum+=arr[i]-arr[i-m];
		ans = max(ans, sum+frontSum);
	}
	cout << ans;
	return 0;
}