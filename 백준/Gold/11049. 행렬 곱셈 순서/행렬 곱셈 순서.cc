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
int cost[501][501],s[501][2];

int dp(int i,int j){
    int ret=INF;
    if(i==j) return cost[i][j];
    else if(cost[i][j]!=0) return cost[i][j];
    else{
        for(int k=i;k<j;k++){
            int sum;
            sum=s[i][0]*s[k][1]*s[j][1];
            ret = min(ret,dp(i,k)+dp(k+1,j)+sum);
        }
        cost[i][j]=ret;
        return ret;
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i][0] >> s[i][1];
    }
        
    cout << dp(0,n-1);
        
    return 0;
}