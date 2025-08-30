#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

const int N = 1030;

int n,m;
int arr[N][N], dp[N][N];

void update(int x,int y, int c){
    arr[x][y]=c;
    for(int j=1;j<=n;j++){
        dp[x][j] = dp[x][j-1] + arr[x][j];
    }
}

int sum(int x1,int y1,int x2,int y2){
    int res=0;
    for(int i=x1;i<=x2;i++){
        res += dp[i][y2] - dp[i][y1-1];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
	
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            dp[i][j] = dp[i][j-1] + arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int w; cin >> w;
        if(w==0){
            int x,y,c; cin >> x >> y >> c;
            update(x,y,c);
        }else if(w==1){
            int x1,x2,y1,y2; cin >> x1 >> y1 >> x2 >> y2;
            int res = sum(x1,y1,x2,y2);
            cout << res << '\n';
        }

    }
    return 0;
}