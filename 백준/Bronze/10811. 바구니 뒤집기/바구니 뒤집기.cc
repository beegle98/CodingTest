#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int s[31];
int main(){
    FASTIO
    
    int n,m; cin >> n >> m;
    vi s;
    for(int i=1;i<=n;i++){
        s.push_back(i);
    }
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        reverse(s.begin()+a-1,s.begin()+b);
    }
    for(int i=0;i<n;i++){
        cout << s[i] << ' ';
    }
    return 0;
}
