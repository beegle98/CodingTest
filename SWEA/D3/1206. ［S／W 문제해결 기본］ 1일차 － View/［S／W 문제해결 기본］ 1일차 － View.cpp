#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int s[1111];
 
int main(){
    FASTIO
 
    int ans,T=10;
    for(int t=1;t<=T;t++){
        
        int n; cin >> n;
        int sum=0;
        for(int i=0;i<n;i++){
            cin >> s[i];
        }
        for(int i=2;i<n-2;i++){
            int tmp=s[i]-max({s[i-2],s[i-1],s[i+1],s[i+2]});
            if(tmp>0) sum+=tmp;
        }
        ans = sum;
        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}