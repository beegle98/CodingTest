#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

 
int main(){
    FASTIO
 
    int ans,T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int test_case;
        cin >> test_case;
        int Max,sum[101];
        Max=0;
        memset(sum,0,sizeof(int)*101);

        for(int i=0;i<1000;i++){
            int x; cin >> x;
            sum[x]++;
            if(sum[x]>=Max){
                Max=sum[x];
                ans=x;
            }
        }
    
        cout << "#" << test_case << ' ' << ans << '\n';
    }
    return 0;
}