#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
	int n,k; cin >> n >> k;
    vi s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    int st=0, ed=0;
    int cnt=0, ans=0;
    while(ed<n){
        if(s[ed]&1) cnt++;
        ed++;
        ans = max(ans,ed-st-cnt);
        while(cnt>k){
            if(s[st]&1) cnt--;
            st++;
        }
    }
    cout << ans;
    return 0;
}