#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int N,S,arr[100];
map<int,int> sub;
ll ans=0;

void left(int st, int sum){
    if(st==N/2){
        sub[sum]++;
        return;
    }
    left(st+1,sum+arr[st]);
    left(st+1,sum);
}
void right(int st, int sum){
    if(st==N){
        ans += sub[S-sum];
        return;
    }
    right(st+1,sum+arr[st]);
    right(st+1,sum);
}

int main(){
    FASTIO
    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> arr[i];
    
    left(0,0);
    right(N/2,0);
    
    if(!S) cout << ans-1;
    else cout << ans;
}