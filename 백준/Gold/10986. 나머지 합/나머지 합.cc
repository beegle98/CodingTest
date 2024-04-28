#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

ll sum[1000100],cnt[1001];

int main(){
    FASTIO
    
    int n,m; cin >> n >> m;
    sum[0]=0;
    cnt[0]=1;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        sum[i]=(sum[i-1]+x)%m;
        cnt[sum[i]]++;
    }
    ll ans=0;
    for(int i=0;i<m;i++){
        ll tmp=cnt[i];
        ans+=tmp*(tmp-1)/2;
    }
    cout << ans;
    return 0;
}