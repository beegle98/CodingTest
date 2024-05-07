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
        int s[10];
		queue<int> q;
		for(int i=0;i<8;i++){
			int x; cin >> x;
			q.push(x);
		}
		int tmp=1,cnt=1;
		while(tmp>0){
			tmp=q.front();
			q.pop();
			tmp-=cnt;
			if(tmp<0) tmp = 0;
			q.push(tmp);
			cnt=cnt%5+1;
		}
		
        cout << "#" << tc << ' ';
		for(int i=0;i<8;i++){
			cout << q.front() << ' ';
			q.pop();
		}
		cout << '\n';
    }
    return 0;
}