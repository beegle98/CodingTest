#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MAX = 1e9;
string s;
int dp[2002];
bool isPalindrome(int l,int r){
    while(l<=r){
        if(s[l++]!=s[r--]) return false;
    }
    return true;
}
int main() {
    FASTIO
    cin >> s;
    int n = s.size();
    fill(dp,dp+n+1,MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+1;
        for(int j=1;j<i;j++){
            if(isPalindrome(j-1,i-1)) {
				dp[i] = min(dp[i],dp[j-1]+1);
			}
        }
    }
    cout << dp[n];
    return 0;
}