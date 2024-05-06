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
 
    int ans,T=10;
    for(int t=1;t<=T;t++){

		int tc; cin >> tc;
		string str,token;
		cin >> token;
		cin >> str;
		int cnt=0;
		for(int i=0;i<str.size();i++){
			if(str[i]==token[0]){
				int key=1;
				for(int j=0;j<token.size();j++){
					if(str[i+j]!=token[j]){
						key=0;
						break;
					}
				}
				cnt+=key;
			}
		}
		ans = cnt;
        cout << "#" << tc << ' ' << ans << '\n';
    }
    return 0;
}
