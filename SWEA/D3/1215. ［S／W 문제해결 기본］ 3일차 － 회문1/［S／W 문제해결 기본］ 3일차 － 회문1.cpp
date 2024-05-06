#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

char str[10][10];
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
    //FASTIO
 
    int ans=0,T=10;
    for(int t=1;t<=T;t++){

		cin >> n;
		for(int i=0;i<8;i++){
			cin >> str[i];
		}
		int sum=0;
		for(int i=0;i<8;i++){
			for(int j=0;j<=8-n;j++){
				sum += palx(i,j);
				sum += paly(j,i);
			}
		}
		ans = sum;
        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}
