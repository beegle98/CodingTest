#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

vector<string> ss={"ZRO","ONE","TWO","THR","FOR","FIV","SIX","SVN","EGT","NIN"};
 
int main(){
    FASTIO
     
    int T=10; cin >> T;
    for(int t=1;t<=T;t++){
         
        int n;
		string a; cin >> a >> n;
		vi ans;
        for(int i=0;i<n;i++){
			string s; cin >> s;
			if(s=="ZRO"){
				ans.push_back(0);
			}
			else if(s=="ONE"){
				ans.push_back(1);
			}
			else if(s=="TWO"){
				ans.push_back(2);
			}
			else if(s=="THR"){
				ans.push_back(3);
			}
			else if(s=="FOR"){
				ans.push_back(4);
			}
			else if(s=="FIV"){
				ans.push_back(5);
			}
			else if(s=="SIX"){
				ans.push_back(6);
			}
			else if(s=="SVN"){
				ans.push_back(7);
			}
			else if(s=="EGT"){
				ans.push_back(8);
			}
			else if(s=="NIN"){
				ans.push_back(9);
			}
		}
		sort(ans.begin(),ans.end());
        cout << "#" << t << ' ';
		for(int i=0;i<n;i++){
			cout << ss[ans[i]] << ' ';
		}
		cout << '\n';
    }
    return 0;
}