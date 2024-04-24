#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

const int N = 100;

int main(){
    FASTIO
 
    int ans,T=10;
    for(int t=1;t<=T;t++){
        
        int dump; cin >> dump;
        int d1[N+1],d2[N+1],sum=0;
        memset(d1,0,sizeof(int)*(N+1));
        memset(d2,0,sizeof(int)*(N+1));
        for(int i=0;i<N;i++){
            int x; cin >> x;
            d1[x]++;
            d2[x]++;
            sum+=x;
        }
        int n,high=0,low=101;
        n=dump;
        for(int i=N;i>=1;i--){
            
            n-=d1[i];
            d1[i-1]+=d1[i];
            if(n<=0){
                if(n==0) high=i-1;
                else high=i;
                break;
            }
        }
        n=dump;
        for(int i=1;i<=N;i++){
            n-=d2[i];
            d2[i+1]+=d2[i];
            if(n<=0){
                if(n==0) low=i+1;
                else low=i;
                break;
            }
        }
        
        if(low>=high){
            ans = sum / N;
            if(sum%N) ans++;
        }
        else ans = high - low;

        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}