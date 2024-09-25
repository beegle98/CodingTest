#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<int> vi;
int main() {
	FASTIO
	
	int n; cin >> n;
	vi index(n+1), v(n+1);
	
	//첫 번째 수열의 인덱스를 저장
	for(int i=1;i<=n;i++){
		int x; cin >> x;
		index[x]=i;
	}
	//두 번째 수열을 입력받고 해당 숫자의 첫 번째 수열에서의 인덱스를 v[i]에 저장
	for(int i=1;i<=n;i++){
		int x; cin >> x;
		v[i]=index[x];
	}
	//v[i]로 LIS 돌리면 끝
	vi lis;
	lis.push_back(v[1]);
	for(int i=2;i<=n;i++){
		if(lis.back()<v[i]) lis.push_back(v[i]);
		else{
			int iter = lower_bound(lis.begin(),lis.end(),v[i])-lis.begin();
			lis[iter]=v[i];
		}
	}
	cout << lis.size();
	return 0;
}