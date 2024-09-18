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
	// 입력
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	int ans = 0;
	// 누적합 계산
	// ld[x][y] = x,y 좌표에서 왼쪽 아래 대각선으로 1이 이어진 최대 개수
	// rd[x][y] = x,y 좌표에서 오른쪽 아래 대각선으로 1이 이어진 최대 개수
	// 아래쪽부터 누적합 계산
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(arr[i][j]==1){
				rd[i][j]=rd[i+1][j+1]+1;
				ld[i][j]=ld[i+1][j-1]+1;
			}
		}
	}
	// k = min(ld, rd)값부터 1까지 다이아몬드가 생성 가능한지 확인한다.
	// 왼쪽 대각선 끝의 좌표에서 rd 값과 오른쪽 대각선 끝의 좌표에서 ld값이 둘 다 k 이상이면 생성 가능하다.
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int k = min(ld[i][j],rd[i][j]);
			while(k > ans){
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