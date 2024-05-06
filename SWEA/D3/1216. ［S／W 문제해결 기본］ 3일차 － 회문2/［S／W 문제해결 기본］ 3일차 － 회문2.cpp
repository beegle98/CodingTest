#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

char str[111][111];
int n;
int palx(int x,int y){
	for(int i=0;i<n;i++){
		if(str[x][y+i]!=str[x][y+n-1-i]){
			return 0;
		}
	}
	return 1;
}
int paly(int x,int y){
	for(int i=0;i<n/2;i++){
		if(str[x+i][y]!=str[x+n-1-i][y]){
			return 0;
		}
	}
	return 1;
}

int main(){
    FASTIO
 
    int ans=0,T=10;
    for(int t=1;t<=T;t++){

		int tc; cin >> tc;
		for(int i=0;i<100;i++){
			cin >> str[i];
		}
		ans=0;
		for(n=100;n>0;n--){
			for(int i=0;i<100;i++){
				for(int j=0;j<=100-n;j++){
					if(palx(i,j)) ans=n;
					else if(paly(j,i)) ans=n;
				}
			}
			if(ans>0) break;
		}
		
        cout << "#" << tc << ' ' << ans << '\n';
    }
    return 0;
}
