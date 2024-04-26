#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

vll s;
int n;
ll ans[2],Min=2000000001;

int main(){
    FASTIO
    
    cin >> n;
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        s.push_back(x);

    }
    sort(s.begin(),s.end());

    int l=0,r=n-1;
    while(l<r){
        ll sum = s[l]+s[r];
        if(abs(sum)<Min){
            Min = abs(sum);
            ans[0]=s[l];
            ans[1]=s[r];
        }
        if(sum==0) break;
        else if(sum<0){
            l++;
        }
        else{
            r--;
        }
    }
    cout << ans[0] << ' ' << ans[1];
    return 0;
}