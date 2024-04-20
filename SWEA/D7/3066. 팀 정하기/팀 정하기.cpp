// 수 색칠하기
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
      
    int test_case; cin >> test_case;
    for(int t=1;t<=test_case;t++){
        
        int ans,n,m,k;
        cin >> n >> m >> k;
        int r1,r2;
        if(n<=m*2){
            r1=n%2;
            r2=m-(n/2);
        }
        else{
            r1=n-(m*2);
            r2=0;
        }
        n-=r1;
        m-=r2;
        k-=r1+r2;
        ans=m;
        if(k>0){
            ans-=k/3;
            if(k%3) ans--;
        }
        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}
