#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

ll dp[101][101];
int n, arr[101][101];
ll recur(int x,int y){
    if(x<0 || x>=n || y<0 || y>=n) return 0;
    if(x==n-1 && y==n-1) return 1;
    if(dp[x][y] || arr[x][y]==0) return dp[x][y];
    return dp[x][y] = recur(x+arr[x][y],y) + recur(x,y+arr[x][y]);
}

int main(){
    FASTIO

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    ll ans = recur(0,0);
    cout << ans;
    return 0;
}