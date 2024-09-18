#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
const int N = 800;
int n,m;
int ld[N][N], rd[N][N];
int arr[N][N];

int main() {
	//FASTIO
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	int ans = 0;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(arr[i][j]==1){
				rd[i][j]=rd[i+1][j+1]+1;
				ld[i][j]=ld[i+1][j-1]+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int k = min(ld[i][j],rd[i][j]);
			//cout << k << '\n';
			while(k > 0){
				if(rd[i+k-1][j-k+1] >= k && ld[i+k-1][j+k-1]>=k){
					ans = max(ans, k);
				}
				k --;
			}
		}
	}

	cout << ans;
	return 0;
}