#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
	int n; cin >> n;
    vi arr(n+1);
    for(int i = 1; i <= n;i++) cin >> arr[i];
    ll ans=0, sum=0;
    for(int i=n;i>=1;i--){
        sum+=arr[i];
        if(sum>0) ans += sum;
        else sum=0;
    }
    cout << ans;
    return 0;
}