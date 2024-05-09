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
    int n=1;
    while(n>0){
		int sum=1;
		vi s; s.push_back(1);
		cin >> n;
		if(n==-1) break;
		for(int i=2;i*i<n;i++){
			if(n%i==0){
				sum+=i;
				s.push_back(i);
				if(i*i!=n){
					sum+=n/i;
					s.push_back(n/i);
				}
			}
		}
		if(sum==n){
			sort(s.begin(),s.end());
			cout << n << " = " << s[0];
			for(int i=1;i<s.size();i++){
				cout << " + " << s[i];
			}
			cout << '\n';
		}
		else{
			cout << n << " is NOT perfect.\n";
		}
	}
    return 0;
}