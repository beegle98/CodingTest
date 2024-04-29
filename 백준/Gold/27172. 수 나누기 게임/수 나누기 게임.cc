#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
  
int ans[1000100];
bool d[1000100];

int main(){
    FASTIO
    int n; cin >> n;
    vi s;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        s.push_back(x);
        d[x]=true;
    }
    for(int i=0;i<n;i++){
        for(int j=s[i]*2;j<=1000000;j+=s[i]){
            if(d[j]){
                ans[s[i]]++;
                ans[j]--;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[s[i]] << ' ';
    }
    return 0;
}