#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;


int main(){
    FASTIO
    string s; cin >> s;
    int n = s.size();
    int ans,cnt[2];
    cnt[0]=0;
    cnt[1]=0;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            cnt[s[i-1]-'0']++;
        }
    }
    cnt[s[n-1]-'0']++;
    ans = min(cnt[0],cnt[1]);
    cout << ans;
    return 0;
}
