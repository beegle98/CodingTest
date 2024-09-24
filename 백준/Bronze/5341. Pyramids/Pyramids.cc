#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;

int main() {
	FASTIO
	
	ll n;
	while(cin >> n){
		if(n==0) break;
		cout << n*(n+1)/2 << '\n';
	}
	return 0;
}