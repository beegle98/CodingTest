#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int cnt[100],arr[100];

int main()
{
    FASTIO
    int ans=0,n; cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    
    for(int i=0;i<n-1;i++){
        pll Max={1,arr[i+1]-arr[i]};
        cnt[i]++;
        cnt[i+1]++;
        for(int j=i+2;j<n;j++){
            ll x = j-i;
            ll y = arr[j]-arr[i];
            if(Max.second*x<Max.first*y){// b/a < d/c -> bc < ad  (a,c는 양수)
                Max = {x,y};
                cnt[i]++;
                cnt[j]++;
            }
        }
        ans = max(ans, cnt[i]);
    }
    ans = max(ans,cnt[n-1]);
    cout << ans;
    return 0;
}