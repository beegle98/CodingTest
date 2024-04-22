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
    
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i;j++) cout << ' ';
        for(int j=0;j<i*2-1;j++) cout << '*';
        cout << '\n';
    }
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<n-i;j++) cout << ' ';
        for(int j=0;j<i*2-1;j++) cout << '*';
        cout << '\n';
    }
    return 0;
}