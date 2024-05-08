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
     
    int n,k; cin >> n >> k;
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(n%i==0) cnt++;
		if(cnt==k){
			ans=i;
			break;
		}
	}
	cout << ans;
    return 0;
}