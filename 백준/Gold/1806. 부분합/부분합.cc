#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

ll sum[100100];

int main(){
    FASTIO
 
    int n; cin >> n;
    ll m; cin >> m;

    for(int i=1;i<=n;i++){
        int x; cin >> x;
        sum[i]=sum[i-1]+x;
    }
    int l=0,Min=0;
    for(int i=1;i<=n;i++){
        if(sum[i]-sum[l]>=m){
            while(sum[i]-sum[l]>=m){
                l++;
            }
            l--;
            if(i-l<Min || Min==0) Min = i-l;
        }
    }
    cout << Min;
    return 0;
}