#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int s[1111][3],dp[1111][3];

int main(){
	int n, Min=10000000;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s[i][0] >> s[i][1] >> s[i][2];
    }
	for(int i=0;i<3;i++) dp[0][i]=s[0][i];
	for(int i=0;i<3;i++){//마지막에서 i번째를 선택했을 경우
		
		int l,r;
		l=(i+2)%3;
		r=(i+1)%3;
		dp[1][i]=s[1][i]+min(dp[0][l],dp[0][r]);
		dp[1][l]=s[1][l]+dp[0][r];
		dp[1][r]=s[1][r]+dp[0][l];
		for(int j=2;j<n-1;j++){
			dp[j][0]=s[j][0]+min(dp[j-1][1],dp[j-1][2]);
			dp[j][1]=s[j][1]+min(dp[j-1][2],dp[j-1][0]);
			dp[j][2]=s[j][2]+min(dp[j-1][0],dp[j-1][1]);
		}
		dp[n-1][i]=s[n-1][i]+min(dp[n-2][l],dp[n-2][r]);
		if(Min > dp[n-1][i]) Min = dp[n-1][i];
	}
	cout << Min;
	return 0;
}