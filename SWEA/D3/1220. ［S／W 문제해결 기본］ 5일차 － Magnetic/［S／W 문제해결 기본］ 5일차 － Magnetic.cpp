#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);


int main(){
    FASTIO
 
    int ans,T=10;
	int s[101][101];
    for(int t=1;t<=T;t++){

		int n; cin >> n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> s[i][j];
			}
		}
		ans=0;
		for(int i=0;i<n;i++){
			int stat=0;
			for(int j=0;j<n;j++){
				if(s[j][i]==1) stat=1;
				else if(s[j][i]==2){
					if(stat==1){
						ans++;
						stat=2;
					}
				}
			}
		}
        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}
