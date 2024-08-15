#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


const int N=(1<<16);
const int INF = 987654321;

int cost[20][20], n, p, full_bit;
int dp[N];

int DFS(int cnt, int visited){

    if(cnt == p) return 0;
    if(dp[visited] != -1) return dp[visited];

    dp[visited] = INF;

    for(int i=0;i<n;i++){ // 켜주는 발전소 위치 i
        if((visited & (1<<i))==0) continue; // 
        for(int j=0;j<n;j++){ // 켜야하는 발전소 위치 j
            if((visited & 1<<j)!=0) continue; // 꺼져있어야함
            dp[visited] = min(dp[visited], cost[i][j] + DFS(cnt+1,visited | 1<<j));
        }
    }

    return dp[visited];

}


int solve(){
    cin >> n;
    full_bit=(1<<n)-1;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> cost[i][j];
        }
    }
	string str; cin >> str;
	cin >> p;
	int ans, initCnt = 0, initBit = 0;
	for(int i=0;i<n;i++){
		if(str[i]=='Y'){
            initBit |= (1<<i);
            initCnt++;
        }
	}
    if(initCnt >= p){
        return 0;
    }else if(initCnt==0){
        return -1;
    }
    return DFS(initCnt, initBit);
}

int main()
{

    int ans;
    ans = solve();
    cout << ans << '\n';
    return 0;
}