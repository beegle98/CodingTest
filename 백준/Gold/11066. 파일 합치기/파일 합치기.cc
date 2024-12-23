#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

#define INF 1987654321
int T,n,x;
int cost[501][501],sum[501];

int dp(int i,int j){
    int ret=INF;
    if(i==j) return cost[i][j];
    else if(cost[i][j]!=0) return cost[i][j];
    else{
        for(int k=i;k<j;k++){
            ret = min(ret,dp(i,k)+dp(k+1,j)+sum[j+1]-sum[i]);
        }
        cost[i][j]=ret;
        return ret;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    

    cin >> T;
    int s[501];
    for(int k=0;k<T;k++){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> s[i];
        }
        for(int i=1;i<=n;i++){
            sum[i] = sum[i-1]+s[i-1];
            //cout << sum[i] << '\n';
        }
        
        memset(cost,0,sizeof(cost));
        
        cout << dp(0,n-1) << '\n';
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << cost[i][j] << "   ";
            }
            cout << '\n';
        }*/
    }
    return 0;
}