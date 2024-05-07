#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int n,m,s[2222];
bool dp[2222][2222];

void f(int l,int r){
    while(l>=0 && r<n){
        if(s[l]==s[r]){
            dp[l][r]=1;
        }
        else break;
        l--;
        r++;
    }
}
int main(){
    FASTIO
 
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
        dp[i][i]=1;
    }
    for(int i=0;i<n-1;i++){
        f(i,i+1);
        f(i-1,i+1);
    }

    cin >> m;
    for(int i=0;i<m;i++){
        int l,r; cin >> l >> r;
        cout << dp[l-1][r-1] << '\n';
    }
    return 0;
}